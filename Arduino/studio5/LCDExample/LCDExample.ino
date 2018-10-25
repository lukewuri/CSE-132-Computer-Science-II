/***************************************************************************************************************/
// Created from example code from Arduino Playground ( http://playground.arduino.cc/Code/LCD )
//    LCD_ST7036_v1.2.0.zip ( https://bitbucket.org/fmalpartida/st7036-display-driver/wiki/Home )
// Extract .zip file to the arduinosketchfolder/libraries/ folder. You may need to create the libraries subfolder
// if its your first library. Restart the IDE. You can set the arduinosketchfolder under File -> Preferences
// Changed ST7036 object instantiation to (2,16,0x7c) for our display (2x16 with I2C address = 0x7c)
/***************************************************************************************************************/
#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

ST7036 lcd = ST7036 ( 2, 16, 0x7c );

void setup ()
{
  lcd.init ();
  lcd.setContrast(0);
}

int i = 0 ;
void loop ()
{
  lcd.clear ();
  lcd.print ("CSE132");
  lcd.setCursor (1,0);
  lcd.print ("is FUN!");
  lcd.setCursor ( 1, 12 );
  lcd.print (i++ % 32);
  delay (500);
}
