//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include <vector>
#include <algorithm>
using std::vector;

int knapSack01(vector<int> Wts, vector<int> Vals, int Weight){
    const int row = Wts.size();
    vector<vector<int>> dp(row + 1, vector<int>(Weight + 1, 0));
    for(int i = 1; i <= row; ++i){
        for(int j = 1; j <= Weight; ++j){
            if(Wts[i-1] <= j)
                dp[i][j] = std::max(Vals[i-1] + dp[i-1][j-Wts[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[row][Weight];
}