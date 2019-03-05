// https://leetcode.com/problems/find-the-duplicate-number/

#include <vector>
using std::vector;

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================
// 面试题3（一）：找出数组中重复的数字

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.empty())
            return -1;

        for(int i = 0; i < nums.size(); ++i)
            while(nums[i] != i + 1){
                if(nums[i] == nums[nums[i]-1])
                    return nums[i];
                std::swap(nums[i], nums[nums[i]-1]);
            }

        return -1;
    }
};


// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-287-find-the-duplicate-number/
// Binary Search
// Find the smallest m such that len(nums <= m) > m, which means m is the duplicate number.
int findDuplicate(vector<int>& nums) {
    int l = 1;
    int r = nums.size();
    while(l < r){
        int count = 0;
        int mid = l + (r - l) / 2;
        for(int x: nums)
            if(x <= mid)
                ++count;

        if(count > mid)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

