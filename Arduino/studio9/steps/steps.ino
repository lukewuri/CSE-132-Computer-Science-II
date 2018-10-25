/* sequence
 *  
 *  CSE 132 - Studio 9
 *  
 *  Fill this out so we know whose studio this is.
 *  
 *  Name:Luke Wuri
 *  WUSTL Key:lwuri
 *  
 *  Name: Billy Guo
 *  WUSTL Key: billy.guo
 *  
 *  Name: Kevin Lee
 *  WUSTL Key: kevinlee
 *  
 *  Name:
 *  WUSTL Key:
 *  
 */

#include <Arduino.h>
#include <Wire.h>
#include "ST7036.h"
#include "Adafruit_MMA8451.h"
#include "Adafruit_Sensor.h"

Adafruit_MMA8451 mma = Adafruit_MMA8451();
ST7036 lcd = ST7036 ( 2, 16, 0x7c );

void setup ()
{
 Serial.begin(115200);
  
  Serial.println("Adafruit MMA8451 test!");

  lcd.init();
  lcd.setContrast(0);  
  lcd.setCursor(0,0);

  if (! mma.begin()) {
    Serial.println("Couldnt start");
    lcd.print("Couldnt start");
    while (1);
  }
  Serial.println("MMA8451 found!");
  
  mma.setRange(MMA8451_RANGE_8_G);
  
  Serial.print("Range = "); Serial.print(2 << mma.getRange());  
  Serial.println("G");

  lcd.print("Orientation");
}

void loop ()
{
  lcd.clear ();
  // insert code here as needed

// Read the 'raw' data in 14-bit counts
  mma.read();
  long x_g = (long) 100*mma.x_g;
  long y_g = (long) 100*mma.y_g;
  long z_g = (long) 100*mma.z_g;
  int counter = 0;
  Serial.print(x_g);
//  while (counter < 4){
//    Serial.write(x_g >> ((3-counter)*8));
//    Serial.write(x_g >> ((3-counter)*8));
//    Serial.write(x_g >> ((3-counter)*8));
//    counter++;
//  }

  
  /* Get a new sensor event */ 
  sensors_event_t event; 
  mma.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: \t"); Serial.print(event.acceleration.x); Serial.print("\t");
  Serial.print("Y: \t"); Serial.print(event.acceleration.y); Serial.print("\t");
  Serial.print("Z: \t"); Serial.print(event.acceleration.z); Serial.print("\t");
  Serial.print("m/s^2 ");
  
  /* Get the orientation of the sensor */
  uint8_t o = mma.getOrientation();
  
  
  
 lcd.setCursor (1,0);
 switch (o) {
    case MMA8451_PL_PUF: 
      Serial.println("Portrait Up Front");
      lcd.print("Pt Up Front     ");
      break;
    case MMA8451_PL_PUB: 
      Serial.println("Portrait Up Back");
      lcd.print("Pt Up Back      ");
      break;    
    case MMA8451_PL_PDF: 
      Serial.println("Portrait Down Front");
      lcd.print("Pt Down Front   ");
      break;
    case MMA8451_PL_PDB: 
      Serial.println("Portrait Down Back");
      lcd.print("Pt Down Back    ");
      break;
    case MMA8451_PL_LRF: 
      Serial.println("Landscape Right Front");
      lcd.print("Lscp Right Front");
      break;
    case MMA8451_PL_LRB: 
      Serial.println("Landscape Right Back");
      lcd.print("Lscp Right Back ");
      break;
    case MMA8451_PL_LLF: 
      Serial.println("Landscape Left Front");
      lcd.print("Lscp Left Front ");
      break;
    case MMA8451_PL_LLB: 
      Serial.println("Landscape Left Back");
      lcd.print("Lscp Left Back  ");
      break;
    }
//  Serial.println();
  delay(10);
   



}
