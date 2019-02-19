// https://leetcode.com/problems/house-robber-ii/
#include <vector>
#include <algorithm>
using std::vector;

int rob(vector<int>& nums, int l, int r);   //  [l, r)
int rob(vector<int>& nums){
    if(nums.empty())
        return 0;
    if(nums.size() == 1)
        return nums[0];
    return std::max(rob(nums, 0, nums.size()-1), rob(nums, 1, nums.size()));
}

int rob(vector<int>& nums, int l, int r){
    int sz = r - l;
    if(sz == 0)
        return 0;

    vector<int> dp(sz + 1);
    dp[0] = 0;
    dp[1] = nums[l];
    for(int i = 2; i <= sz; ++i){
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[l+i-1]);
    }

    return dp[sz];
}