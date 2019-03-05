// https://leetcode.com/problems/coin-change/

#include<vector>
using std::vector;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);     // `-1` mean the invalid
        dp[0] = 0;
        for(int money = 1; money < amount + 1; ++money){
            for(auto coin: coins){  // 循环各个面值，找到dp[i]最优解
                if(money >= coin && dp[money - coin] != -1){    // 表示i可以由面值coins[j]组成；并且dp[i-coins[j]]可以达到，以供后面使用
                    if(dp[money] == -1 || dp[money] > dp[money - coin] + 1) // 表明dp[i]不可达到。或者当前的张数dp[i]不够小，即可以更新dp[i]
                        dp[money] = dp[money - coin] + 1;   //  更新公式（减去某张钞票后张数最少，选这这样的钞票减去）
                }
            }
        }

        return dp[amount];
    }
};