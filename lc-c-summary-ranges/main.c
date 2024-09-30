/*********************************************************************************
 * leetcode solution
 *********************************************************************************/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {

  char** summary = malloc(numsSize * sizeof(char*));
  int counter = 0;
  *returnSize = 0;

  for (int i = 0; i < numsSize; i++) {
    if (nums[i+1] == (nums[i] + 1)) counter++;
    else if () {
      summary[returnSize++] = malloc(25 * sizeof(char));
    }
    else {
      summary[returnSize++] = malloc(25 * sizeof(char));
      counter = 0;
    }
  }

  return summary;
}

/*********************************************************************************
 * driver
 *********************************************************************************/

int main() {
  int numsSize = 6;
  int nums[numsSize] = {0,1,2,4,5,7};
  int* returnSize = 3;
  summaryRanges(nums, numsSize, returnSize);

  int numsSize = 7;
  int nums[numsSize] = {0,2,3,4,6,8,9};
  int* returnSize = 4;
  summaryRanges(nums, numsSize, returnSize);
}
