#include <avr/io.h>

; AVR assembly comments start with a semicolon 
// (or a double slash, like C)
; Lines without labels should be indented once.

.global giveMeMax
giveMeMax:
  ldi r24, 15 // Load the value 1 into register 24
  ret

 // Define further "functions" below:
 // .global functionName
 // functionName:
 //   *code*
 //   ret

.global giveMeZero
giveMeZero:
  ret 0


.global addFour
addFour:
  ldi
