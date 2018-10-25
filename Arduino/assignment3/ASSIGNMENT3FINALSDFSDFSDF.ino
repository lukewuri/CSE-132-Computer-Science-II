int const FILTER_COUNTS = 9;
float celsiusArray[FILTER_COUNTS] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int count = 0;

const int ledPin = 4;
const int analogPin = 0;
const long interval = 250; // prints 4 times every second
long previousTime = 0;
long previousTime2 = 0;
long previousTime3 = 0;
const long BLINK_DURATION = 200;



void setup() {

  Serial.begin(9600);
  analogReference(INTERNAL);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);


}

void loop() {
  unsigned long currentTime = millis();
  float reading = (analogRead(analogPin) * (1.1 / 1023));
  float convertedReading = (((reading) * 100) - 50);
  float chirpThresh = (1000) * ((60) / (7 * (convertedReading) - 30));

  if (currentTime - previousTime >= interval) {
    previousTime = currentTime;
    //y - 25 = (1/10)(x - 750), where y is the celsius reading
    // and x is the reading in mV. y = (1/10)x - 50

    Serial.print(convertedReading);
    Serial.print(", ");



    celsiusArray[count % FILTER_COUNTS] = convertedReading;
    float runningSumAverage = (celsiusArray[0] + celsiusArray[1] + celsiusArray[2] + celsiusArray[3] + celsiusArray[4] + celsiusArray[5] + celsiusArray[6] + celsiusArray[7] +  celsiusArray[8]) / 9;
    count += 1;
    Serial.println(runningSumAverage);
  }
  //Dolbear's Law: T = 10 + (N - 40)/7. where N is the number of chirps in 60 seconds.
  //Rearranging to find N we find N = 7T - 30. Intuitively, we know 60n, where n is the number
  // of chirps in 1 second, is equal to N. We substitute 60 n for N. The final math comes out
  // out to be T = (60n+30)/7, where n is the number of chirps in 1 second. Inverting this
  // to solve for n, we find n = (7T-30)/60. We can then take both sides to the -1 power to find the
  //period, seconds per chirp. We'll use S for seconds per chirp. S = (60)/(7T-30)


  if (currentTime - previousTime3 >= chirpThresh)
  {
    previousTime3 = currentTime;
    if (digitalRead(ledPin) == HIGH)
    {
      if (currentTime - previousTime2 >= BLINK_DURATION)
      {
        previousTime2 = currentTime;
        digitalWrite(ledPin, LOW);
      }
    }
    if (digitalRead(ledPin) == LOW)
    {
      if (currentTime - previousTime2 >= BLINK_DURATION)
      {
        previousTime2 = currentTime;
        digitalWrite(ledPin, HIGH);
      }
    }

  }
}





