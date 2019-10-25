// https://leetcode.com/problems/domino-and-tromino-tiling/

// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-790-domino-and-tromino-tiling/


#include <vector>
using std::vector;


int numTilings(int N) {
    vector<vector<long>> dp(N + 1, vector<long>(3, 0));
    dp[0][0] = 1;
    dp[1][0] = 1;

    constexpr int kMod = 1000000007;

    for (int i = 2; i < N + 1; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]) % kMod;
        dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % kMod;
        dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % kMod;
    }

    return dp[N][0];
}