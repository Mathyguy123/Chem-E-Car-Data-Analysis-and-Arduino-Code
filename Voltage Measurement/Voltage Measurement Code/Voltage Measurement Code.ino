/*
* Author: Abrar Sheikh, 2/16/2023
* Purpose: measures voltage of input source vs time
*/

unsigned long myTime;

int value; //Store value from voltage divider
const int volt = A0; //Voltage measurement analog pin
int max = 0; //Store max voltage

void setup() {
  pinMode(volt, INPUT);
  Serial.begin(9600); //Set up the console
}

void loop() {
  // put your main code here, to run repeatedly:
  myTime = millis();  //Time of data collection

  value = analogRead(volt);  //Analog value read by volt port (between 0 and 1023)
  if (value>max){
    max = value; //Collect max voltage reading
  }

  Serial.print(myTime);
  Serial.print(",");
  Serial.print(value/209.0);
  Serial.print(",");
  Serial.println(max/209.0);
  

}