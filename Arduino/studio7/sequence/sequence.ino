/* sequence
 *  
 *  CSE 132 - Studio 7
 *  
 *  Fill this out so we know whose studio this is.
 *  
 *  Name:
 *  WUSTL Key:
 *  
 *  Name:
 *  WUSTL Key:
 *  
 *  Name:
 *  WUSTL Key:
 *  
 *  Name:
 *  WUSTL Key:
 *  
 */

#include <Arduino.h>
#include <Wire.h>
#include <ST7036.h>

ST7036 lcd = ST7036 ( 2, 16, 0x7c );

void setup ()
{
  lcd.init ();
  lcd.setContrast(0);
  // insert code here as needed




}

void loop ()
{
  lcd.clear ();
  // insert code here as needed





}
