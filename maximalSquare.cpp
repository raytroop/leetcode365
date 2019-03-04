// https://leetcode.com/problems/maximal-square/

#include <vector>
#include <algorithm>
using std::vector;

// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-221-maximal-square/
int maximalSquare(vector<vector<char>>& matrix){
    if(matrix.empty())
        return 0;
    const int Row = matrix.size();
    const int Col = matrix[0].size();

    vector<vector<int>> dp(Row + 1, vector<int>(Col + 1, 0));
    // dp[i][j] => max size of matrix[i-1][j-1] as bottom right
    int ans = 0;
    for(int i = 1; i <= Row; ++i)
        for(int j = 1; j <= Col; ++j)
            if(matrix[i-1][j-1] == '1'){
                dp[i][j] = std::min(dp[i-1][j-1], std::min(dp[i-1][j], dp[i][j-1])) + 1;
                ans = std::max(dp[i][j], ans);
            }



    return ans * ans;
}