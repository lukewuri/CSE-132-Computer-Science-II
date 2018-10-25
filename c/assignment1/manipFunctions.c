/* 
 * manipFunctions.c
 * 
 * This source file defines all the functions used to bit manipulate
 *
 */

#include "manipFunctions.h"

int hasAOne(int num) {
  return (num || 0);
}

int hasAZero(int num) {
  return (~num || 0);
}

int leastSigHasAOne(int num) {

  return ((num<<24)||0);

}

int negate(int num) {
  return (~num+1);
}

int isNegativeInt(int num) {
  return((num >> 31)||0);
}

int isNegativeLong(long num) {
  return((num >> 63) || 0);
}

int isNegativeChar(char num) {
  return ((num >> 7) || 0);
}
