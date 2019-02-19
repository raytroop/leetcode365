// https://leetcode.com/problems/merge-sorted-array/
// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
/* Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6] */

#include <vector>
#include <algorithm>
using std::vector;

void mergeSortedArray(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m + n - 1;
    --m;
    --n;
    while(n >= 0 && m >= 0){
        if(nums1[m] <= nums2[n])
            nums1[i--] = nums2[n--];
        else
            nums1[i--] = nums1[m--];
    }

    while(n >= 0)
        nums1[i--] = nums2[n--];
}
