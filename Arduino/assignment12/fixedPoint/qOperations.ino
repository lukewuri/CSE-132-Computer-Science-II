#define K   (1 << (15 - 1))

float qtof(int number, int fractionalBits) { //take integer in Q format and conver to float
  // TODO complete
  int numberQ = number;
  int n = fractionalBits;
  
  float result1 = (((float) numberQ)*(pow(2, -n)));
  
  
  
  return result1;
}

int ftoq(float number, int fractionalBits) {
  // TODO complete
  float numberF = number;
  int n = fractionalBits;
  
  float step1 = numberF*(pow(2,n));
  int step2 = (int) step1;
  
  
  return step2;
}

int qMultiply(int a, int b, int fractionalBits) {
  // TODO complete
  int n = fractionalBits;
  long temp;
 

  temp = ((long)a)*((long)b);
  int result = (temp >> 15);

 
  
  
  
  return result;
}

