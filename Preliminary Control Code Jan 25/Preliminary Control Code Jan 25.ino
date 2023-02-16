int value; //Store value from photoresistor
const int pRes = A0; //Photoresistor analog pin
const int motor = A1; //Motor analog pin (previously digital and used for LED)

void setup() {
  pinMode(pRes, INPUT);
  pinMode(motor, OUTPUT);
  Serial.begin(9600); //Set up the console
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(pRes);  
  Serial.println(value);

  if (value>=300){
    analogWrite(motor, 200);
  }
  else{
    analogWrite(motor, 0);
  }

}