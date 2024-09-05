/* Given an integer array nums and an integer val, remove all occurrences of val in 
 * nums in-place. The order of the elements may be changed. Then return the number 
 * of elements in nums which are not equal to val.
 *
 * Consider the number of elements in nums which are not equal to val be k, to get 
 * accepted, you need to do the following things:
 * - Change the array nums such that the first k elements of nums contain the elements 
 *   which are not equal to val. The remaining elements of nums are not important as 
 *   well as the size of nums.
 * - Return k.
 */

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
  int numRemove = 0;
  
  /* Using the var `newSize`, increment through array and increase counter for
   * every element that has the same value as `val`. Replace the removed space
   * with a non-matching element.
   *
   * The crux of this solution is `i - numRemove` and could be thought of as
   * the program trying to remember the last opening position as a result of
   * an element removal.
   */
  for(int i = 0; i < numsSize; i++) {
    if (nums[i] == val) numRemove++;
    else nums[i - numRemove] = nums[i];
  }

  return (numsSize - newSize);
};

void printArray(int* nums, int numsSize) {
  for (int i = 0; i < (numsSize); i++) {
    printf("nums[%d]: %d\n", i, nums[i]);
  }
  printf("=====================\n");
};

struct Test {
  int nums[100];
  int numsSize;
};

int main() {
  printf("=====================\n");

  struct Test case1;
  case1.numsSize = 4;
  case1.nums[0] = 3;
  case1.nums[1] = 2;
  case1.nums[2] = 2;
  case1.nums[3] = 3;
  int val = 3;
  printArray(case1.nums, 
             removeElement(case1.nums, case1.numsSize, val));

  struct Test case2;
  case2.numsSize = 8;
  case2.nums[0] = 0;
  case2.nums[1] = 1;
  case2.nums[2] = 2;
  case2.nums[3] = 2;
  case2.nums[4] = 3;
  case2.nums[5] = 0;
  case2.nums[6] = 4;
  case2.nums[7] = 2;
  val = 2;
  printArray(case2.nums, 
             removeElement(case2.nums, case2.numsSize, val));

  return 0;
};
