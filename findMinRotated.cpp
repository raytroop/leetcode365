// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <vector>
using std::vector;

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solution/
/* Algorithm
1. Find the mid element of the array.
2. If mid element > first element of array this means that we need to look for the inflection point on the right of mid.
3. If mid element < first element of array this that we need to look for the inflection point on the left of mid. */
int findMin(vector<int> &nums)
{
    int l = 0;
    int r = nums.size();
    // the list has just one element OR there is no rotation
    if (r == 1 || nums[0] < nums[r - 1])
        return nums[0];

    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] < nums[0])
            r = mid;
        else
            l = mid + 1;
    }
    return nums[l];
}