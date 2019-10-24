// https://leetcode.com/problems/longest-common-subsequence/


#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::max;

int longestCommonSubsequence(string text1, string text2) {
    const int rows = text1.length();
    const int cols = text2.length();
    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
    for (int i = 1; i < rows + 1; ++i)
        for (int j = 1; j < cols + 1; ++j) {
            if (text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    return dp[rows][cols];
}