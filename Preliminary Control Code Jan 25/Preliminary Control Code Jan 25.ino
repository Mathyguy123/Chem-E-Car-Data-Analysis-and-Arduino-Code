int value; //Store value from photoresistor
const int pRes = A0; //Photoresistor analog pin
const int led = 13;

void setup() {
  pinMode(pRes, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600); //Set up the console
}

void loop() {
  // put your main code here, to run repeatedly:
  value = analogRead(pRes);  
  Serial.println(value);

  if (value>=270){
    digitalWrite(led, HIGH);
  }
  else{
    digitalWrite(led, LOW);
  }

}
