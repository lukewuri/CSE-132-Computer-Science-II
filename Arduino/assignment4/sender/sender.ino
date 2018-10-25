/* sender
 *
 *  CSE 132 - Assignment 4
 *
 *  Fill this out so we know whose assignment this is.
 *
 *  Name:Luke Wuri
 *  WUSTL Key:lwuri
 *
 *  and if two are partnered together
 *
 *  Name:
 *  WUSTL Key:
 */


const unsigned long deltaTime = 1000; // loop period (in ms)
long loopEndTime = deltaTime;
int const FILTER_COUNTS = 9; //for case 36, array
long celsiusArray[FILTER_COUNTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(DEFAULT);
}

void loop() {
  // put your main code here, to run repeatedly:


  if (millis() >= loopEndTime) {
    loopEndTime += deltaTime;

    sendDebug("asdfg"); //case 30

    Serial.write(0x21);//case 32
    Serial.write(0x32);
    unsigned long message = millis();
    unsigned long shiftedMessage = message >> 24;
    unsigned long shiftedMessage2 = message >> 16;
    unsigned long shiftedMessage3 = message >> 8;
    unsigned long shiftedMessage4 = message;
    Serial.write(shiftedMessage);
    Serial.write(shiftedMessage2);
    Serial.write(shiftedMessage3);
    Serial.write(shiftedMessage4);

    //case 33 potentiometer
    Serial.write(0x21);
    Serial.write(0x33);
    unsigned int reading = analogRead(A1);
    unsigned int shiftedReading = reading >> 8;
    unsigned int shiftedReading2 = reading;
    Serial.write(shiftedReading);
    Serial.write(shiftedReading2);

    //case 34 - A/D temperature
    Serial.write(0x21);
    Serial.write(0x34);
    int temperature = analogRead(A0);
    int shiftedTemperature = temperature >> 8;
    int shiftedTemperature2 = temperature;
    Serial.write(shiftedTemperature);
    Serial.write(shiftedTemperature2);

    //case 35 - unfiltered celisus
    Serial.write(0x21);
    Serial.write(0x35);
    long longTemperature = analogRead(A0);//value 0-1023

    long celsiusTemperature = (longTemperature * 0.4887585533) - 50;
    long shiftedCelsius = celsiusTemperature >> 24;
    long shiftedCelsius2 = celsiusTemperature >> 16;
    long shiftedCelsius3 = celsiusTemperature >> 8;
    long shiftedCelsius4 = celsiusTemperature;
    Serial.write(shiftedCelsius);
    Serial.write(shiftedCelsius2);
    Serial.write(shiftedCelsius3);
    Serial.write(shiftedCelsius4);

    //case 36
    Serial.write(0x21);
    Serial.write(0x36);
    celsiusArray[count % FILTER_COUNTS] = celsiusTemperature;
    long runningSumAverage = (celsiusArray[0] + celsiusArray[1] + celsiusArray[2] + celsiusArray[3] + celsiusArray[4] + celsiusArray[5] + celsiusArray[6] + celsiusArray[7] +  celsiusArray[8]) / 9;
    count += 1;
    long shiftedRunning = runningSumAverage >> 24;
    long shiftedRunning2 = runningSumAverage >> 16;
    long shiftedRunning3 = runningSumAverage >> 8;
    long shiftedRunning4 = runningSumAverage;
    Serial.write(shiftedRunning);
    Serial.write(shiftedRunning2);
    Serial.write(shiftedRunning3);
    Serial.write(shiftedRunning4);


    if (celsiusTemperature >= 100) { //case31
      sendError("error");
    }
  }

}

void sendDebug(char* stuff) {
  // String z = (String)stuff;

  Serial.write(0x21);//send magic number !
  Serial.write(0x30);//send key 0x30
  Serial.write(strlen(stuff));
  for (int i = 0; i <= (strlen(stuff)); i++) {
    Serial.write(stuff[i]);
  }
}

void sendError(char* thing) {
  Serial.write(0x21);
  Serial.write(0x31);
  for (int u = 0; u <= strlen(thing); u++) {
    Serial.write(thing[u]);
  }

}





