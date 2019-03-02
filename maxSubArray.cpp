// https://leetcode.com/problems/maximum-subarray/

#include <vector>
#include <algorithm>
using std::vector;

int maxSubArray(vector<int>& nums) {
    int prev = nums[0];
    int ans = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        prev = (prev > 0) ? prev + nums[i] : nums[i];
        ans = std::max(prev, ans);
    }

    return ans;
}