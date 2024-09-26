/* Given an array of positive integers nums and a positive integer target, return the 
 * minimal length of a subarray whose sum is greater than or equal to target. If there 
 * is no such subarray, return 0 instead.
 */
#include <stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize) {
  int minLen = 0;    // minimum length of subarray w sum >= target; default = 0
  int currLen = 0;        // current len of subarr
  int currSum = 0;        // current sum of subarr
  int leftBound = 0;      // subarray left bound
  int rightBound = 0;     // subarray right bound

  int firstMin = 1;

  // increments the subarray right bound until the end of the subarray
  for (rightBound = 0; rightBound < numsSize; rightBound++) {
    currSum += nums[rightBound];

    // trim off values on left side of subarray so long subarray sum >= target
    while ((currSum - nums[leftBound]) >= target && leftBound < rightBound) {
      currSum -= nums[leftBound];
      leftBound += 1;
    }

    // update minLen for shorter subarray length w sum >= target
    currLen = rightBound - leftBound + 1;
    if (firstMin == 1 && currSum >= target) {     // gets the init minLen
      minLen = currLen;
      firstMin = 0;
    }
    else if (currSum >= target && currLen < minLen) minLen = currLen;
  }

  return minLen;
}

struct Test {
  int nums[100];
  int numsSize;
};

int main() {

  // solution: 2
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

  // solution: 1
  struct Test case2;
  case2.numsSize = 3;
  case2.nums[0] = 1;
  case2.nums[1] = 4;
  case2.nums[2] = 4;
  tar = 4;
  printf("minLen: %d\n", minSubArrayLen(tar, case2.nums, case2.numsSize));
  printf("===========================================\n");

  // solution: 0
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

  // solution: 3
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

  // solution: 2
  struct Test case5;
  case5.numsSize = 10;
  case5.nums[0] = 5;
  case5.nums[1] = 1;
  case5.nums[2] = 3;
  case5.nums[3] = 5;
  case5.nums[4] = 10;
  case5.nums[5] = 7;
  case5.nums[6] = 4;
  case5.nums[7] = 9;
  case5.nums[8] = 2;
  case5.nums[9] = 8;
  tar = 15;
  printf("minLen: %d\n", minSubArrayLen(tar, case5.nums, case5.numsSize));
  printf("===========================================\n");


  return 0;
};
