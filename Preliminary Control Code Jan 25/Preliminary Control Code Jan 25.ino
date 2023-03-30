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
  
  value = analogRead(pRes);  
  Serial.println(value);

  if (Zero == true){
    start = value;
  }
  Serial.println(start);

  Zero = false;

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