//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

#include <vector>
#include <algorithm>
#include <cassert>
using std::vector;

int maxProductAfterCutting(int length){
    if(length < 2)
        return 1;
    vector<int> dp(length + 1);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= length; ++i){
        int max_ = i;
        for(int j = 1; j <= i / 2; ++j)
            max_ = std::max(dp[j] * dp[i - j], max_);
        dp[i] = max_;
    }

    return dp[length];
}

int main(){
    int ans = maxProductAfterCutting(8);
    assert(ans == 18);

    return 0;
}