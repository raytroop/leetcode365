#include <vector>
using std::vector;


int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    if (obstacleGrid[0][0] != 1)
        dp[1][1] = 1;

    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (i == 1 && j == 1)
                continue;
            if (obstacleGrid[i - 1][j - 1])
                continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m][n];
}