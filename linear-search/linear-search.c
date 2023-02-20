/* 
 * In order to manifest and develop a passion for algorithms and the logic behind them, I have 
 * decided to try to study algorithm every daym and have a reasonable understanding of its
 * implementation and tradeoffs within the week. The algorithms will be implemeneted in an
 * arbitrary langauge, with likely aribitrary libraries, given that I am to provide a reason 
 * for its usage. This is largely so that I am forced to develop a deeper understanding of the 
 * tools that I use. The first algorithm in this collection will be the implementation of a 
 * simple algorithm: Linear Search.
 *
 * Linear Search is likely the easiest algorithm to implement while also one of the most efficient 
 * given that the input size is reasonably small. The algorithm traverses through each individual
 * element in a data set until the desired element has been identified.
 *
 * The algorithm was implemented in C due to how both the programming language and algorithm
 * parallel one another in basic concept. Both are very simple. It just felt fitting.
 */
#include <stdio.h>        /* - The library contains the printf function, which will be used to send
                           *   an output to stdout
                           * - Contains sizeof function. When given an argument, returns the size in
                           *   the unit of bytes. 
                           */

/**
 * @brief Linear search algorithm. Returns the position of the desired element in the array. 
 *
 * The algo has the running time O(n), as in the worst case that the searched element is located at 
 * the end of the data set, the array is required to traverse from the beginning towards the end 
 * through each individual elementWhile this isn't an issue for smaller data sets, the algorithm 
 * will likely be noticeably inefficient for larger data sets. In the best case, the element is 
 * conveniently placed at the front which has a running time of O(1).
 * 
 * @param input 
 * @param n 
 * @param identify 
 * @return int 
 */
int linearSearch(int input[], int n, int identify) {
  for (int i = 0; i < n; i++) {        // traverses through the array, given the array's address
    if (*(input + i) == identify)     /* the compiler understands that incrementing an array's
                                       * address is to move along the array relative to the 
                                       * address */
      return i;
  }

  return -1;
} // end linearSearch

/**
 * @brief The driver code. The code initializes an array that is to act as a test input for the 
 * algorithm. The array will be passed as one of the parameters for the function that executes 
 * the linear search algorithm.
 * 
 * @return int 
 */
int main() {
  int input[]  = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};       // Array of size n
  int n        = sizeof(input)/sizeof(input[0]);       // Size of array
  int identify = 9;                                    // Desired element

  int position = linearSearch(input, n, identify);     // passes array to Linear Search for processing
  printf("The element is at position %d \n",   // outputs the position of the searched element
  position);
  
  return 0;
} // end main