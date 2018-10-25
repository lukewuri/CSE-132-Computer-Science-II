// Replace with your completed library code!

float qtof(int number, int fractionalBits) {
 int numberQ = number;
  int n = fractionalBits;
  float result1 = (((float) numberQ)*(pow(2, -n)));
  return result1;
}

int ftoq(float number, int fractionalBits) {
  float numberF = number;
  int n = fractionalBits;
  float step1 = numberF*(pow(2,n));
  int step2 = (int) step1;
  return step2;
}

int qMultiply(int a, int b, int fractionalBits) {
 int n = fractionalBits;
  long temp;
  temp = ((long)a)*((long)b);
  int result = (temp >> 15);
  return result;
}

