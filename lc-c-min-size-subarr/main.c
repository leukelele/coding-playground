/* Given an array of positive integers nums and a positive integer target, return the 
 * minimal length of a subarray whose sum is greater than or equal to target. If there 
 * is no such subarray, return 0 instead.
 */
#include <stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
  return minLen;
}

struct Test {
  int nums[100];
  int numsSize;
};

int main() {

  printf("===========================================\n");
  struct Test case1;
  case1.numsSize = 6;
  case1.nums[0] = 2;
  case1.nums[1] = 3;
  case1.nums[2] = 1;
  case1.nums[3] = 2;
  case1.nums[4] = 4;
  case1.nums[5] = 3;
  int tar = 7;
  printf("minLen: %d\n", minSubArrayLen(tar, case1.nums, case1.numsSize));
  printf("===========================================\n");

  struct Test case2;
  case2.numsSize = 3;
  case2.nums[0] = 1;
  case2.nums[1] = 4;
  case2.nums[2] = 4;
  tar = 4;
  printf("minLen: %d\n", minSubArrayLen(tar, case2.nums, case2.numsSize));
  printf("===========================================\n");

  struct Test case3;
  case3.numsSize = 6;
  case3.nums[0] = 1;
  case3.nums[1] = 1;
  case3.nums[2] = 1;
  case3.nums[3] = 1;
  case3.nums[4] = 1;
  case3.nums[5] = 1;
  tar = 11;
  printf("minLen: %d\n", minSubArrayLen(tar, case3.nums, case3.numsSize));
  printf("===========================================\n");

  struct Test case4;
  case4.numsSize = 5;
  case4.nums[0] = 1;
  case4.nums[1] = 2;
  case4.nums[2] = 3;
  case4.nums[3] = 4;
  case4.nums[4] = 5;
  tar = 11;
  printf("minLen: %d\n", minSubArrayLen(tar, case4.nums, case4.numsSize));
  printf("===========================================\n");

  return 0;
}
