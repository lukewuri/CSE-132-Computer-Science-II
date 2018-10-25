/* morse

    CSE 132 - Assignment 5

    Fill this out so we know whose assignment this is.

    Name:Kevin Lee
    WUSTL Key:kevinlee

    and if two are partnered together

    Name:Luke Wuri
    WUSTL Key:lwuri
*/

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>
#include "morse.h"
#define dot 500
#define dash 1500
#define space 500
#define lSpace 1500
#define wSpace 3500
#define ledPin 2
long previousMillis = 0;
int ledState = LOW;
int line = 0;

ST7036 lcd = ST7036 ( 2, 16, 0x7c );


void setup() {
  lcd.init ();
  lcd.setContrast(0);
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  if (Serial.available() > 0) {
    int incomingByte = Serial.read();
    if (incomingByte == 10) {
      if (line == 0) {
        line = 1;
        lcd.setCursor(line, 0);
      }
      else {
        line = 0;
        lcd.setCursor(line, 0);
        lcd.clear();
      }
    }
    int convertedByte = convertByte(incomingByte);
    
    if (convertedByte >= 0) {
      if (incomingByte != 10 && incomingByte != 13) {
      lcd.print((char)incomingByte);
    }
      for (int i = 0; i < 5; i++) {
        ledState = LOW;
        digitalWrite(ledPin, ledState);
        while (currentMillis - previousMillis <= space) {
          currentMillis = millis();
        }
        previousMillis = currentMillis;
        ledState = HIGH;
        digitalWrite(ledPin, ledState);
        if ((int)morse_chars[convertedByte][i] == 1) {
          while (currentMillis - previousMillis <= dot) {
            currentMillis = millis();
          }
          previousMillis = currentMillis;
          ledState = LOW;
          digitalWrite(ledPin, ledState);
        }
        if ((int)morse_chars[convertedByte][i] == 3) {
          while (currentMillis - previousMillis <= dash) {
            currentMillis = millis();
          }
          previousMillis = currentMillis;
          ledState = LOW;
          digitalWrite(ledPin, ledState);
        }
        if ((int)morse_chars[convertedByte][i] == 0 && convertedByte == 36) {
          ledState = LOW;
          digitalWrite(ledPin, ledState);
          while (currentMillis - previousMillis <= wSpace) {
            currentMillis = millis();
          }
          previousMillis = currentMillis;
          break;
        }
        if ((int)morse_chars[convertedByte][i] == 0 && convertedByte != 36) {
          ledState = LOW;
          digitalWrite(ledPin, ledState);
          while (currentMillis - previousMillis <= lSpace) {
            currentMillis = millis();
          }
          previousMillis = currentMillis;
          break;
        }
      }
    }
  }
}

