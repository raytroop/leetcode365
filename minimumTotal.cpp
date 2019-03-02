// https://leetcode.com/problems/triangle/

#include <vector>
#include <algorithm>
#include <climits>
using std::vector;


int minimumTotal(vector<vector<int>>& triangle) {
    if(triangle.empty())
        return -1;
    const int Rows = triangle.size();
    vector<vector<int>> dp(Rows + 1, vector<int>(Rows + 1, INT_MAX));
    for(int i = 1; i <= Rows; ++i)
        for(int j = 1; j <= i; ++j){
            if(i == 1 && j == 1)
                dp[i][j] = triangle[i-1][j-1];
            else
                dp[i][j] = std::min(dp[i-1][j-1], dp[i-1][j]) + triangle[i-1][j-1];
        }

    return *std::min_element(dp[Rows].cbegin(), dp[Rows].cend());
}