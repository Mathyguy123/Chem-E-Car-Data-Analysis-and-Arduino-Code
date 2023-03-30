/*
* Author: Abrar Sheikh, 2/21/2023
* Purpose:
* This program allows a constant current load to be drawn from a power source, and measures
* said current to show what is actually being taken.
*/

//Pins
const int vset = 9; //Used to control current load circuit based on user input
const int iread = A4; 

//Constants and arrays
float readings[256]; //Stores PWM voltage readings to average out shunt resistor voltage
int count = 0;
float sum = 0; //Stores sum of readings

//Setup user interface
#include <LiquidCrystal.h>
#include <ezButton.h>
LiquidCrystal lcd(10, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 
unsigned long lastCount1 = 0; //Stores 1s place for set current
unsigned long lastCount2 = 0; //Stores 10s place for set current
unsigned long lastCount3 = 0; //Stores 100s place for set current
int lastrs = 0;  //Shunt resistance index
int lastCurr = 0; //Stores last current reading (rounded)

ezButton button1(13); //Changes 1s place for set current
ezButton button2(12); //Changes 10s place for set current
ezButton button3(11); //Changes 100s place for set current
ezButton chooseRS(8); //Changes shunt resistance
float res[] = {2.0, 5.2, 10.1, 46.6, 98.5, 997.0}; //Shunt resistance choices
int choices = 6; //Number of choices for resistances

void setup() {
  // put your setup code here, to run once:
  //Setup serial and pins
  Serial.begin(9600);
  pinMode(vset, OUTPUT);
  pinMode(iread, INPUT);

  //Setup user interface
  lcd.begin(16,2); // Setup LCD
  button1.setDebounceTime(50);
  button1.setCountMode(COUNT_FALLING);
  button2.setDebounceTime(50);
  button2.setCountMode(COUNT_FALLING);
  button3.setDebounceTime(50);
  button3.setCountMode(COUNT_FALLING);
  chooseRS.setDebounceTime(50);
  chooseRS.setCountMode(COUNT_FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Making buttons collect data
  button1.loop();
  button2.loop();
  button3.loop();
  chooseRS.loop();
  unsigned long count1 = button1.getCount()%10;
  unsigned long count2 = button2.getCount()%10;
  unsigned long count3 = button3.getCount()%10;
  int rs = chooseRS.getCount()%choices;

  //Getting resistor selected
  float curRs = res[rs];

  //Computing maximum current draw allowed
  float maxI = 4.5/curRs*1000;
  int setI = count1+count2*10+count3*100;

  if (setI>= maxI){
    setI = maxI;
  }

  analogWrite(vset, int(setI*curRs/1000.0*51));

  float realCurr = analogRead(iread)/209.0*1000/curRs;
  sum = sum+realCurr-readings[count];
  readings[count] = realCurr;

  int avgCurr = round(sum/256.0);
  Serial.println(avgCurr);

  count = (count+1)%256;

   //If there is a change in variables from last time, update LCD screen
  if (lastCount1 != count1 || lastCount2 != count2 || lastCount3 != count3 || lastrs != rs || lastCurr != avgCurr){
    lcd.clear();
    lcd.setCursor(0, 0); // start to print at the first row
    lcd.print("RS: ");
    lcd.print(int(curRs));
    lcd.print("R I:");
    
    //Safety feature for current draw
    if (setI <= maxI){
      lcd.print(setI);
      lcd.print("mA");
    }
    else{
      setI = maxI;
      lcd.print(setI);
      lcd.print("mA");
    }

    lcd.setCursor(0, 1);
    lcd.print("Re I:");
    lcd.print(avgCurr);
    lcd.print("mA");


    lastCount1 = count1;
    lastCount2 = count2;
    lastCount3 = count3;
    lastrs = rs;
    lastCurr = avgCurr;
  }

}
