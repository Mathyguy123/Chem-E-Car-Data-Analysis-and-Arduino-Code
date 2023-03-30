#include <LiquidCrystal.h>
#include <ezButton.h>
LiquidCrystal lcd(10, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 
unsigned long lastCount1 = 0;
unsigned long lastCount2 = 0;
unsigned long lastCount3 = 0;

ezButton button1(13);
ezButton button2(12);
ezButton button3(11);

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
}

void loop() {
  // put your main code here, to run repeatedly:
  button1.loop();
  button2.loop();
  button3.loop();
  unsigned long count1 = button1.getCount()%10;
  unsigned long count2 = button2.getCount()%10;
  unsigned long count3 = button3.getCount()%10;

  if (lastCount1 != count1){
    lcd.clear();
    lcd.setCursor(1, 1); // start to print at the first row
    lcd.cursor();
    lcd.print("Current: ");
    lcd.print(count1+count2*10+count3*100);
    lcd.print(" mA");

    lastCount1 = count1;
  }

  if (lastCount2 != count2){
    lcd.clear();
    lcd.setCursor(1, 1); // start to print at the first row
    lcd.cursor();
    lcd.print("Current: ");
    lcd.print(count1+count2*10+count3*100);
    lcd.print(" mA");

    lastCount2 = count2;
  }

  if (lastCount3 != count3){
    lcd.clear();
    lcd.setCursor(1, 1); // start to print at the first row
    lcd.cursor();
    lcd.print("Current: ");
    lcd.print(count1+count2*10+count3*100);
    lcd.print(" mA");

    lastCount3 = count3;
  }
}

/*
* Arduino LCD Tutorial
*
* Crated by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/

/*#include <LiquidCrystal.h> // includes the LiquidCrystal Library 
#include <ezButton.h>
LiquidCrystal lcd(10, 2, 4, 5, 6, 7); // Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7) 
unsigned long lastCount = 0;
ezButton button1(13);

void setup() { 
 Serial.begin(9600);
 lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
 button1.setDebounceTime(50);
 button1.setCountMode(COUNT_FALLING);

}

void loop() { 
 lcd.setCursor(2,1); // Sets the location at which subsequent text written to the LCD will be displayed
 lcd.print(89); // Prints "Arduino" on the LCD
 delay(3000); // 3 seconds delay 
 /*delay(3000); // 3 seconds delay 
 lcd.setCursor(2,1); // Sets the location at which subsequent text written to the LCD will be displayed 
 lcd.print("LCD Tutorial"); 
 delay(3000); 
 lcd.clear(); // Clears the display 
 lcd.blink(); //Displays the blinking LCD cursor 
 delay(4000); 
 lcd.setCursor(7,1); 
 delay(3000); 
 lcd.noBlink(); // Turns off the blinking LCD cursor 
 lcd.cursor(); // Displays an underscore (line) at the position to which the next character will be written 
 delay(4000); 
 lcd.noCursor(); // Hides the LCD cursor 
 lcd.clear(); // Clears the LCD screen 
}*/