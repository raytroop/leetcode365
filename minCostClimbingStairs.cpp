//https://leetcode.com/problems/min-cost-climbing-stairs/

#include <vector>
#include <algorithm>
using std::vector;

int minCostClimbingStairs(vector<int>& cost){
    const int n = cost.size();
    if(n == 0)
        return 0;
    if(n == 1)
        return cost[0];
    if(n == 2)
        return std::min(cost[0], cost[1]);

    vector<int> dp(n, 0);
    for(int i = 2; i < n ; ++i)
        dp[i] = std::min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);

    return std::min(dp[n-1] + cost[n-1], dp[n-2] + cost[n-2]);
}