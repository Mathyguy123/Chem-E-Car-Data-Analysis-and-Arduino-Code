#include <LiquidCrystal.h>
#include <ezButton.h>
LiquidCrystal lcd(10, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 
unsigned long lastCount1 = 0;
unsigned long lastCount2 = 0;
unsigned long lastCount3 = 0;
int lastrs = 0;  //Shunt resistance index

ezButton button1(13); //Changes 1s place
ezButton button2(12); //Changes 10s place
ezButton button3(11); //Changes 100s place
ezButton chooseRS(8); //Changes shunt resistance
float res[] = {2.0, 5.2, 10.1, 46.6, 98.5, 997.0}; //Shunt resistance choices
int choices = 6; //Number of choices for resistances

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
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
  button1.loop();
  button2.loop();
  button3.loop();
  chooseRS.loop();
  unsigned long count1 = button1.getCount()%10;
  unsigned long count2 = button2.getCount()%10;
  unsigned long count3 = button3.getCount()%10;
  int rs = chooseRS.getCount()%choices;

  float curRs = res[rs];

  float maxI = 5.0/curRs*1000;

  if (lastCount1 != count1 || lastCount2 != count2 || lastCount3 != count3 || lastrs != rs){
    int setI = count1+count2*10+count3*100;

    lcd.clear();
    lcd.setCursor(0, 0); // start to print at the first row
    lcd.print("RS: ");
    lcd.print(int(curRs));
    lcd.print("R I:");
    
    //lcd.setCursor(1, 1); // start to print at the second row
    //lcd.cursor();
    //lcd.print("Current: ");
    if (setI <= maxI){
      lcd.print(setI);
      lcd.print("mA");
    }
    else{
      setI = maxI;
      lcd.print(setI);
      lcd.print("mA");
    }

    lastCount1 = count1;
    lastCount2 = count2;
    lastCount3 = count3;
    lastrs = rs;
  }

}
