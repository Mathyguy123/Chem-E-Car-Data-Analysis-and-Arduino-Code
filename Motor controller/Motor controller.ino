/*
* Created: Jan 25 2023   Modified: Mar 29, 2023
* Author: Abrar Sheikh
* This code is responsible for controlling the motors in the Chem-E-Car based on the iodine clock stopping mechanism.
*/

int value; //Store value from photoresistor
const int pRes = A0; //Photoresistor analog pin
const int motor = A1; //Motor analog pin (previously digital and used for LED)
bool Zero = true;
int start;

void setup() {
  pinMode(pRes, INPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600); //Set up the console
}

void loop() {
  // put your main code here, to run repeatedly:
  
  //Measuring brightness on a scale of 0 to 1023, and recording it
  value = analogRead(pRes);  
  Serial.println(value);

  //If this is the first value, record it in start, and set Zero to false
  if (Zero == true){
    start = value;
  }
  Zero = false;

  //If voltage drop exceeds 1.3V (endpoint of rxn), cut power to motor, else power it
  if (start-value>=209*1.3){
    analogWrite(motor, 0);
    Serial.println("True");
  }
  else{
    analogWrite(motor, 200);
    Serial.println("False");
  }

  Serial.println();

}