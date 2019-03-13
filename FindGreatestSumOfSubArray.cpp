#include <vector>
#include <algorithm>
using std::vector;
//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

int FindGreatestSumOfSubArray(vector<int> pData){
    if(pData.empty())
        return 0;
    const int sz = pData.size();
    vector<int> dp(sz);
    dp[0] = pData[0];
    int ans = dp[0];
    for(int i = 1; i < sz; ++i){
        if(dp[i-1] > 0)
            dp[i] = dp[i-1] + pData[i];
        else
            dp[i] = pData[i];

        ans = std::max(ans, dp[i]);
    }

    return ans;
}