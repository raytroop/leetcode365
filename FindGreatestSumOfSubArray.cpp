#include <vector>
#include <algorithm>
using std::vector;

int FindGreatestSumOfSubArray(vector<int> pData){
    if(pData.empty())
        return 0;
    const int sz = pData.size();
    vector<int> dp(sz);
    dp[0] = pData[0];
    int ans = dp[0];
    for(int i = 1; i < sz; ++i){
        if(dp[i-1] > 0){
            dp[i] = dp[i-1] + pData[i];
        }
        else
        {
            dp[i] = pData[i];
        }
        ans = std::max(ans, dp[i]);

    }

    return ans;
}