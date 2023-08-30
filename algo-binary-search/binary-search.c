/**
 * @file binary_search.c
 * @author lewkelele
 * @brief An implementation of the binary search algorithm. 
 *
 *        Due to the nature of the algorithm, there is actually multiple approaches to implementing the algorithm. 
 *        It's simplicity allows for the algorithm to be to be implemented following an iterative method, but its 
 *        repetitive sectioning suggests a potential for a recursive implementation. This, however, makes me wonder 
 *        if there is a method for implementing linear search recursively. The approach would likely be very 
 *        overcomplicated for no reason.
 *
 *        The algorithm is to be implemented in C so that I may further practice using the programming language and
 *        debugger GDB.
 * @version 0.1
 * @date 2022-09-16
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>

/**
 * @brief Execution of binary search. The algorithm follows the design method of "divide and conquer." 
 *
 *        It is possible that you might have implemented the algorithm before without knowing. For instance, 
 *        someone asks you to guess a number between 10, with unlimited guesses and hints. Rather than 
 *        approaching it with a linear search mindset, you elect to approach the game methodically. You would 
 *        likely begin with some number at the middle: 5. You are told that your guess is less than the actual
 *        number, so you guess the number in between 5 and 10: 8. You are told the number is less than 8, so
 *        you guess a number between 5 and 8: 6. Correct!
 *        
 *        The algorithm divides the subproblems in half continuously. The worst-case running time would be 
 *        O(log n) and the best-case, if the desired element is at the middle of the data set, is O(1).
 *        Although, it is also worth noting that computer hardware is very efficient with linear execution -
 *        that is, in the case of a small data set, linear search may be faster due to the efficiency of CPU
 *        at executing instructions in order.
 *        - This is further explained in better detail here -> https://www.youtube.com/watch?v=FJJTYQYB1JQ&t=763s
 * 
 * @param input 
 * @param n 
 * @param find
 * @return int 
 */
int binarySearch(int input[], int n, int find) {
  int identified = -1;    // position of desired element if in array
  
/**
 * - 220917 currently there is an error in the logic of the code, though I am not sure as to where it might be. My 
 *   best guess is that the issue may likely be somewhere found in the usage of 'n'.
 * - 220918:1858 The issue is that the block is stuck in an infinite loop. Most of the operations of the algorithm 
 *   works correctly, it properly divides the data set. The issue occurs when it reaches towards the end of the loop 
 *   where there is conflict. I will just have to write it out to see what it wrong.
 * - 220918:1908 THE ISSUE WAS THAT I DID NOT INCLUDE A METHOD FOR BREAKING THE LOOP. It is likely impossible for 
 *   the while loop to ever break due to how the variable 'end' is assigned 'n', which is the size of the array 
 *   (not starting at 0). The variables 'beginning' and 'end' will likely never be equivalent to one another, hence 
 *   it will be no different to placing 'true' as the condition. This conclusion may be flawed upon further thought.
 *   I will have to analyze this more thoroughly at another time as the loop will not terminate if the element is
 *   not in the data set.
 *   220921:0050 I think the issue lies with the assignmnet for 'end', instead of 'n' why not 'n - 1'.
 *   220921:0051 I was right.
 */
  int beginning  = 0;
  int end        = n - 1;
  while (beginning != end) {
    int midpt   = (beginning + end) / 2;
    int current = *(input + midpt);

    if (current == find) {
      identified = current;
      break;
    }

    else if (current > find) end       = midpt;
    else if (current < find) beginning = midpt;
  }

  return identified;
} // end binarySearch

/**
 * @brief The driver code. The code initializes an array that is to act as a test input for the 
 * algorithm. The array will be passed as one of the parameters for the function that executes 
 * the binary search algorithm.
 * 
 * @return int 
 */
int main () {
  int input[]  = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};       // Array of size n
  int n        = sizeof(input)/sizeof(input[0]);       // Size of array
  int find     = -1;                                    // Desired element

  int position = binarySearch(input, n, find);
  printf("The element is at position %d \n",   // outputs the position of the searched element
  position);

  return 0;
} // end main