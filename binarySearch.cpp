//https://leetcode.com/problems/binary-search/

#include <vector>
using std::vector;

// template [l, r)
int search(vector<int>& nums, int target){
    int l = 0;
    int r = nums.size();
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