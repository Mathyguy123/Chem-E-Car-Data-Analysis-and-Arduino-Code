#include <ezButton.h>

unsigned long lastCount = 0;
ezButton button(13);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  button.setDebounceTime(50);
  button.setCountMode(COUNT_FALLING);

}

void loop() {
  // put your main code here, to run repeatedly:
  button.loop();
  unsigned long count = button.getCount();
  if (lastCount != count){
    Serial.println(count);
    lastCount = count;
  }
}
