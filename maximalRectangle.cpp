// https://leetcode.com/problems/maximal-rectangle/

#include <vector>
#include <algorithm>
#include <climits>
using std::vector;

int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty())
        return 0;

    const int Row = matrix.size();
    const int Col = matrix[0].size();

    // dp[i][j] := max len of all 1s ends with col j at row i.
    vector<vector<int>> dp(Row, vector<int>(Col));
    for(int i = 0; i < Row; ++i){
        for(int j = 0; j < Col; ++j){
            if(matrix[i][j] == '0')
                dp[i][j] = 0;
            else{
                dp[i][j] = (j == 0) ? 1 : dp[i][j-1] + 1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < Row; ++i){
        for(int j = 0; j < Col; ++j){
            int len = INT_MAX;
            for(int k = i; k < Row; ++k){
                len = std::min(len, dp[k][j]);
                if(len == 0)
                    break;
                else
                    ans = std::max(ans, (k - i + 1) * len);  // rect area (top->i, bottom->k, right-side->j)
            }
        }
    }

    return ans;
}