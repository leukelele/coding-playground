/*********************************************************************************
 * leetcode solution
 *********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {

  char** summary = malloc(numsSize * sizeof(char*));
  int current = 0;

  for (int i = 0; i < numsSize; i++) {
    while (nums[i+1] == (nums[i] + 1)) {
    }
  }
  return summary;
}

/*********************************************************************************
 * driver
 *********************************************************************************/

int main() {
  int numsSize = 6;
  int nums[6] = {0,1,2,4,5,7};
  int temp = 3;
  int* returnSize = &temp;
  summaryRanges(nums, numsSize, returnSize);

  int numsSize1 = 7;
  int nums1[7] = {0,2,3,4,6,8,9};
  int temp1 = 4;
  int* returnSize1 = &temp1;
  summaryRanges(nums1, numsSize1, returnSize1);
}
