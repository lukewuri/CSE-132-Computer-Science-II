/* indicator
 *
 *  CSE 132 - Assignment 2
 *
 *  Fill this out so we know whose assignment this is.
 *
 *  Name: Luke Wuri
 *  WUSTL Key: lwuri
 *
 *  and if two are partnered together
 *
 *  Name:
 *  WUSTL Key:
 */

int analogPin = 0;
int ledGreen = 3;
int ledBlue = 6;
int ledRed = 5;
int safetyNum = 200;
void setup() {

  Serial.begin(9600);




  pinMode(ledRed, OUTPUT); //red
  pinMode(ledGreen, OUTPUT); //green
  pinMode(ledBlue, OUTPUT); //blue


}

void loop() {


  int analogPin = analogRead(analogPin);
  int convertedAnalogPin = analogPin / (1023 / 255);
  Serial.println(convertedAnalogPin*(5/1023)); //prints out perceived voltage

  if (convertedAnalogPin > safetyNum) //safety red blink
  {
    analogWrite(ledRed, 255);
    analogWrite(ledGreen, 0);
    analogWrite(ledBlue, 0);
    delay(500);
    analogWrite(ledRed, 0);
    analogWrite(ledGreen, 0);
    analogWrite(ledBlue, 0);
    delay(500);
  }
  else
  {
    analogWrite(ledGreen, 255 - convertedAnalogPin);
    analogWrite(ledBlue, convertedAnalogPin);
    analogWrite(ledRed, 0);
  }

}