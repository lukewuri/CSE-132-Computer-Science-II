 .global filterAtIndex
filterAtIndex:
  push r28
  push r29

  ldi r26, lo8(input1)
  ldi r27, hi8(input1)
  lsl r24
  rol r25
  add r26, r24
  adc r27, r25
  ld r24, X+
  ld r25, X
  

  ldi r30, lo8(fir1)
  ldi r31, hi8(fir1)
  lsl r22
  rol r23
  add r30, r22
  adc r31, r23
  ld r22, Z+
  ld r23, Z

  

  push r20
  push r21
  ldi r20, 15
  ldi r21, 0
  
  
  

  call qMultiply //(r24 25, r22 23, r20 21)

  pop r21
  pop r20
  
  add r24, r20
  adc r25, r21
  
  pop r29
  pop r28
  

  ret

