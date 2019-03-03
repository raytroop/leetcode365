// https://leetcode.com/problems/house-robber/
#include <vector>
#include <algorithm>
#include <cassert>
using std::vector;

int rob(vector<int>& nums) {
    const int sz = nums.size();
    if(sz == 0)
        return 0;
    vector<int> dp(sz + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i = 2; i <= sz; ++i){
        dp[i] = std::max(dp[i-1], dp[i-2] + nums[i-1]);
    }

    return dp[sz];
}

int main(){
    vector<int> nums{1,2,3,1};
    assert(rob(nums) == 4);

    return 0;
}