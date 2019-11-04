//https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <vector>
using std::vector;

/*
http://bangbingsyb.blogspot.com/2014/11/leetcode-search-in-rotated-sorted-array.html
A[mid] =  target, 返回mid，否则

(1) A[mid] < A[end]: A[mid+1 : end] sorted
        A[mid] < target <= A[end]  右半，否则左半。

(2) A[mid] > A[end] : A[start : mid-1] sorted
        A[start] <= target < A[mid] 左半，否则右半。
*/

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int start = 0, end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) return mid;

        if (nums[mid] < nums[end]) { // right half sorted
            if (target > nums[mid] && target <= nums[end])
                start = mid + 1;
            else
                end = mid - 1;
        } else {  // left half sorted
            if (target >= nums[start] && target < nums[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
    }
    return -1;
}
