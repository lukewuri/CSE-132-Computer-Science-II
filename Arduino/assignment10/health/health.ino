
#include <Wire.h>
#include <ST7036.h>
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>
int val = 0;
#define aPin 3
unsigned long currentTime;
int x[5] = {};
double y[5] = {};
int i=0;
#define a1 -1.9789467705
#define a2 0.97927235
#define b0 0.01036382
#define b2 -0.01036382
unsigned long previousPeak;
unsigned long currentPeak;
unsigned long beatTime;
unsigned long pulse = 0;
double cum1 = 0;
double cum2 = 0;
double cum3 = 0;
double average1 = 0;
double average2 = 0;
double average3 = 0;
int count = 0;
#define SW1 12

Adafruit_MMA8451 mma = Adafruit_MMA8451();
ST7036 lcd = ST7036 ( 2, 16, 0x7c );


void setup(void) {
  Serial.begin(115200);
  lcd.init ();
  lcd.setContrast(0);
  mma.begin();
  mma.setRange(MMA8451_RANGE_2_G);
  pinMode(SW1, INPUT_PULLUP);
}

void loop() {
//  mma.read();
//  sensors_event_t event; 
  cum1 = 0;
  cum2 = 0;
  cum3 = 0;
  for (int a = 0; a <30; a++){
    mma.read();
    sensors_event_t event; 
    mma.getEvent(&event);
    cum1 = cum1 + event.acceleration.z;
  }
  for (int b = 0; b <30; b++){
    mma.read();
    sensors_event_t event; 
    mma.getEvent(&event);
    cum2 = cum2 + event.acceleration.z;
  }
  for (int c = 0; c <30; c++){
    mma.read();
    sensors_event_t event; 
    mma.getEvent(&event);
    cum3 = cum3 + event.acceleration.z;
  }
  double average1 = cum1/30;
  double average2 = cum2/30;
  double average3 = cum3/30;
  if (average1 < average2 && (average2 - average1) > .02){
    if (average2 > average3 && (average2 - average3) > .02){
      count = count + 1;
    }
  }
  if (digitalRead(SW1) == 0){
    count = 0;
  }
  sendSteps(count);
val = analogRead(aPin);
x[i]= val;
if (i>1){
  y[i]= b0*x[i] + b2*x[i-2] - a1*y[i-1] -a2*y[i-2];
   if (y[i-2] < y[i-1] && y[i-1] > y[i]){
    currentPeak = micros();
    beatTime = currentPeak-previousPeak;
    pulse = 60000000/beatTime;
    previousPeak = currentPeak;
   }
}
else {
  if (i==1){
    y[i]= b0*x[i] + b2*x[i+3] - a1*y[i-1] -a2*y[i+3];
    if (y[i+3] < y[i-1] && y[i-1] > y[i]){
      currentPeak = micros();
      beatTime = currentPeak-previousPeak;
      pulse = 60000000/beatTime;
      previousPeak = currentPeak;
    }
  }
  else {
    if (i==0){
      y[i]= b0*x[i] + b2*x[i+3] - a1*y[i+4] -a2*y[i+3];
      if (y[i+3] < y[i+4] && y[i+4] > y[i]){
        currentPeak = micros();
        beatTime = currentPeak-previousPeak;
        pulse = 60000000/beatTime;
        previousPeak = currentPeak;
      }
    }
  }
}
i = i + 1;
if (i == 5){
  i = 0;
}
pulse = (val + 100)/10;
//Serial.println(val);
//Serial.println(beatTime);
//Serial.println(pulse);
//}
//Serial.println(val);
//sendData(val, currentTime);
//}
sendPulse(pulse);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("STEPS ");
  lcd.setCursor(0,7);
  lcd.print(count);
  lcd.setCursor(1,0);
  lcd.print("PULSE ");
  lcd.setCursor(1,7);
  lcd.print(pulse);
  /* Get the orientation of the sensor */
  uint8_t o = mma.getOrientation();
  
}
void sendSteps(int steps){
  Serial.write(0x21);
  Serial.write(0x30);
  Serial.write(steps >> 8);
  Serial.write(steps);
}
void sendPulse(int value){
  Serial.write(0x21);
  Serial.write(0x31);
  Serial.write(value >> 8);
  Serial.write(value);
}

