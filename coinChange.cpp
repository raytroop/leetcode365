#include<vector>
using std::vector;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int money = 1; money < amount + 1; ++money){
            for(auto coin: coins){
                if(money >= coin && dp[money - coin] != -1){
                    if(dp[money] == -1 || dp[money] > dp[money - coin] + 1)
                        dp[money] = dp[money - coin] + 1;
                }
            }
        }

        return dp[amount];
    }
};