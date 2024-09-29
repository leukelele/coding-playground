/* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int *nums, int numsSize, int target, int *returnSize) {
  int* sums = malloc(2*sizeof(int));
  *returnSize = 0;

  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      if ((nums[i] + nums[j]) == target) {
        *returnSize = 2;
        sums[0] = i;
        sums[1] = j;
        return sums;
      }
    }
  }

  free(sums);
  return NULL;
}


int main(){
  int arr[] = {0, -1, 2, -3, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = -2;
  int returnSize = 2;

  // Call the twoSum function and print the result
  int* sums = twoSum(arr, n, target, &returnSize);
  if (sums != NULL) printf("%d, %d\n", sums[0], sums[1]);

  free(sums);
  return 0;
}

