//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
        engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.*/

#include <vector>
#include <algorithm>
using std::vector;

//https://soulmachine.gitbooks.io/algorithm-essentials/content/java/dp/best-time-to-buy-and-sell-stock-iii.html
//设状态f(i)，表示区间[0,i](0≤i≤n−1)的最大利润
//设状态g(i)，表示区间[i,n-1](0≤i≤n−1)的最大利润
//则最终答案为max{f(i)+g(i)} (0≤i≤n−1)
//允许在一天内买进又卖出，相当于不交易，因为题目的规定是最多两次，而不是一定要两次。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if(n < 2)
            return 0;

        vector<int> f(n);
        f[0] = 0;
        int valley = prices[0];
        for(int i = 1; i < n; ++i){
            valley = std::min(valley, prices[i]);
            f[i] = std::max(f[i-1], prices[i] - valley);
        }

        vector<int> g(n);
        g[0] = 0;
        int peak = prices[n-1];
        for(int i = n - 2; i >= 0; --i){
            peak = std::max(peak, prices[i]);
            g[i] = std::max(g[i + 1], peak - prices[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i)
            ans = std::max(ans, f[i] + g[i]);

        return ans;
    }
};
