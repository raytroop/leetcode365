// https://leetcode.com/problems/minimum-path-sum/

#include <vector>
#include <algorithm>
#include <climits>
using std::vector;


int minPathSum(vector<vector<int>>& grid) {
    if(grid.empty())
        return 0;
    const int Rows = grid.size();
    const int Cols = grid[0].size();
    vector<vector<int>> dp(Rows + 1, vector<int>(Cols + 1, INT_MAX));
    for(int i = 1; i <= Rows; ++i)
        for(int j = 1; j <= Cols; ++j)
            if(i == 1 && j == 1)
                dp[i][j] = grid[i-1][j-1];
            else
                dp[i][j] = std::min(dp[i][j-1], dp[i-1][j]) + grid[i-1][j-1];

    return dp[Rows][Cols];
}