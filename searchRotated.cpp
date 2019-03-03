//https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        const int n = nums.size();
        int minIx = findMinIndex(nums);
        if(minIx == 0)
            return binarySearch(nums, target, 0, n);
        if(target >= nums[0] && target <= nums[minIx-1])
            return binarySearch(nums, target, 0, minIx);
        if(target >= nums[minIx] && target <= nums[n-1])
            return binarySearch(nums, target, minIx, n);

        return -1;

    }

private:
    int binarySearch(vector<int>& nums, int target, int l, int r){
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target)
                return mid;

            if(nums[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }

        return -1;
    }

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solution/
/* Algorithm
1. Find the mid element of the array.
2. If mid element > first element of array this means that we need to look for the inflection point on the right of mid.
3. If mid element < first element of array this that we need to look for the inflection point on the left of mid. */
    int findMinIndex(vector<int> &nums)
    {
        int l = 0;
        int r = nums.size();
        // the list has just one element OR there is no rotation
        if (r == 1 || nums[0] < nums[r - 1])
            return l;

        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[0])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};