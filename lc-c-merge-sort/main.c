/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
 * and two integers m and n, representing the number of elements in nums1 and nums2 
 * respectively.
 * 
 * Merge nums1 and nums2 into a single array sorted in non-decreasing order.
 *
 * The final sorted array should not be returned by the function, but instead be 
 * stored inside the array nums1. To accommodate this, nums1 has a length of m + n, 
 * where the first m elements denote the elements that should be merged, and the last 
 * n elements are set to 0 and should be ignored. nums2 has a length of n.
 *
 * Contraints:
 *   nums1.length == m + n
 *   nums2.length == n
 *   0 <= m, n <= 200
 *   1 <= m + n <= 200
 *   -109 <= nums1[i], nums2[j] <= 109
*/

#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
  int nums1_size = m;
  int nums2_size = n;
  int total_size = m + n;
  
  /* Starting at the end of the array (the side with the greatest values), the loop 
   * compares a value from both arrays. It only iterates backwards on the array 
   * with the largest value.
   *
   * The concept is similar to a common comparison system where the value that most 
   * closely matches a desired characteristic is noted and then removed from the 
   * population pool. This ensures that all elements in the pool are evaluated 
   * individually.
   */
  while ( nums1_size > 0 && nums2_size > 0 ) {
    if ( nums1[(nums1_size - 1)] > nums2[(nums2_size - 1)] ) {
      nums1[--total_size] = nums1[--nums1_size];
    }
    else {
      nums1[--total_size] = nums2[--nums2_size];
    }
  }

  /* This takes into consideration instances in which there are no elements in nums1,
   * while there are elements in nums2. It places the elements of nums2 into nums1 bc
   * nums1 is the array that is evaluatad.
   */
  while ( nums2_size > 0 ) nums1[--total_size] = nums2[--nums2_size];
};

void PrintArray(int* nums1, int m, int n) {
  for ( int i = 0; i < (m + n); i++ ) {
    printf("nums[%d]: %d\n", i, nums1[i]);
  }
  printf("=====================\n");
};

struct Test {
  int nums1[200];
  int nums1_size;

  int nums2[200];
  int nums2_size;
};

int main() {

  printf("=====================\n");

  struct Test case1;
  case1.nums1_size = 3;
  for ( int i = 0; i < case1.nums1_size; i++) case1.nums1[i] = (i + 1);
  case1.nums2_size = 3;
  case1.nums2[0] = 2;
  case1.nums2[1] = 5;
  case1.nums2[2] = 6;
  merge(case1.nums1, case1.nums1_size, case1.nums1_size, case1.nums2, case1.nums2_size, case1.nums2_size);
  PrintArray(case1.nums1, case1.nums1_size, case1.nums2_size);

  struct Test case2;
  case2.nums1_size = 1;
  case2.nums1[0] = 1;
  case2.nums2_size = 0;
  merge(case2.nums1, case2.nums1_size, case2.nums1_size, case2.nums2, case2.nums2_size, case2.nums2_size);
  PrintArray(case2.nums1, case2.nums1_size, case2.nums2_size);

  struct Test case3;
  case3.nums1_size = 0;
  case3.nums2_size = 1;
  case3.nums2[0] = 1;
  merge(case3.nums1, case3.nums1_size, case3.nums1_size, case3.nums2, case3.nums2_size, case3.nums2_size);
  PrintArray(case2.nums1, case2.nums1_size, case2.nums2_size);
};
