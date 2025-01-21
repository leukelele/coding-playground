/* ************************************************************************************
 * F A I L E D
 * This solution does not account for data type bounds.
 * ************************************************************************************
 *
 * Given a non-negative integer x, return the square root of x rounded down to the 
 * nearest integer. The returned integer should be non-negative as well.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* This approach is a more brute force attempt by incrementing (from 0) until an square
 * has been found that surpasses the radicand. When a square > radicand, then a solution
 * should be found as then there is no need to round down too much.
 */
int mySqrt(int x) {
  int radicand = x;
  int brute = 0;
  unsigned long int sqrt = 0;

  while(true) {
    sqrt = brute * brute;
    printf("sqrt: %d\n", sqrt);
    brute++;

    if(sqrt == radicand) {
      return (brute - 1);
    }
    else if(sqrt > radicand) {
      return (brute - 2);
    }
  }

  return -1;
}

int main() {
  printf("2147483647: %d\n", mySqrt(2147483647));
  printf("16: %d\n", mySqrt(16));
  printf("8: %d\n", mySqrt(8));
  printf("4: %d\n", mySqrt(4));
  printf("2: %d\n", mySqrt(2));
}
