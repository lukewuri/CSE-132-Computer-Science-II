/* display
 *  
 *  CSE 132 - Assignment 7
 *  
 *  Fill this out so we know whose assignment this is.
 *  
 *  Name: Luke Wuri
 *  WUSTL Key: lwuri
 *  
 *  Name: Kevin Lee
 *  WUSTL Key: kevinlee
 *  
 */

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
#include "font.h"

#define row0 0
#define row1 1
#define row2 2
#define row3 3
#define row4 4
#define row5 5
#define row6 6

#define col0 7
#define col1 8
#define col2 9
#define col3 10
#define col4 11

#define SW1 12
#define SW2 13
#define SW3 16
#define SW4 15
int pos = 0;

ST7036 lcd = ST7036 ( 2, 16, 0x7c );

void setup ()
{
  lcd.init ();
  lcd.setContrast(0);
  // insert code here as needed
pinMode(row0, OUTPUT);
pinMode(row1, OUTPUT);
pinMode(row2, OUTPUT);
pinMode(row3, OUTPUT);
pinMode(row4, OUTPUT);
pinMode(row5, OUTPUT);
pinMode(row6, OUTPUT);


pinMode(col0, OUTPUT);
pinMode(col1, OUTPUT);
pinMode(col2, OUTPUT);
pinMode(col3, OUTPUT);
pinMode(col4, OUTPUT);

pinMode(SW1, INPUT_PULLUP);
pinMode(SW2, INPUT_PULLUP);
pinMode(SW3, INPUT_PULLUP);
pinMode(SW4, INPUT_PULLUP);


}

void loop ()
{
  //lcd.clear ();
//  delay(200);
  if (digitalRead(SW1) == 0){
    if (pos < 16){
      pos = pos +81;
      delay(200);
    }
    else {
      pos = pos - 16;
      delay(200);
    }
  }//outputs 0 while pressed, outputs 1 while not pressed
  else {
    if (digitalRead(SW4) == 0){
      if (pos > 80) {
        pos = pos -81;
        delay(200);
      }
      else {
        pos = pos + 16;
        delay(200);
      }
    }
    else {
      if (digitalRead(SW2) == 0){
        if (pos == 95){
          pos = 0;
          delay(200);
        }
        else {
          pos = pos +1;
          delay(200);
        }
      }
      else {
        if (digitalRead(SW3) == 0){
          if (pos == 0){
            pos = 95;
            delay(200);
          }
          else {
            pos = pos - 1;
            delay(200);
          }
        }
      }
    }
  }
  lcd.setCursor(0, 0);
  lcd.print((char)(pos+32));

//int a = digitalRead(SW1);
//int b = digitalRead(SW2);
//int c = digitalRead(SW3);
//int d = digitalRead(SW4);
//
//lcd.setCursor(0, 0);
//lcd.print(a);
//lcd.print(b);
//lcd.print(c);
//lcd.print(d);

  // insert code here as needed

//Column = HIGH, Row = LOW, light up
rowOff();
columnOn(col0);
light(font_5x7[pos][0]);
delay(1);
rowOff();
columnOn(col1);
light(font_5x7[pos][1]);
delay(1);
rowOff();
columnOn(col2);
light(font_5x7[pos][2]);
delay(1);
rowOff();
columnOn(col3);
light(font_5x7[pos][3]);
delay(1);
rowOff();
columnOn(col4);
light(font_5x7[pos][4]);
delay(1);
digitalWrite(col0, LOW);
digitalWrite(col1, LOW);
digitalWrite(col2, LOW);
digitalWrite(col3, LOW);
digitalWrite(col4, LOW);



}
void rowOff() {
  digitalWrite(row0, HIGH);
  digitalWrite(row1, HIGH);
  digitalWrite(row2, HIGH);
  digitalWrite(row3, HIGH);
  digitalWrite(row4, HIGH);
  digitalWrite(row5, HIGH);
  digitalWrite(row6, HIGH);
}

void light(int c) {
  int r = 0;
  for (int i = 128; i>1; i= i/2){
    int t = c & i;
    if (!t == 0){
      digitalWrite(r, LOW);
    }
    r++;
  }
}
void columnOn(int c) {
digitalWrite(col0, LOW);
digitalWrite(col1, LOW);
digitalWrite(col2, LOW);
digitalWrite(col3, LOW);
digitalWrite(col4, LOW);
digitalWrite(c, HIGH);
}

