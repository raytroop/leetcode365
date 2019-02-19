//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 #include <vector>
 #include <algorithm>
 using std::vector;

int maxProfit(vector<int>& prices) {
    if(prices.size() < 2)
        return 0;
    int maxdif = prices[1] - prices[0];
    int minPrice = std::min(prices[0], prices[1]);
    for(int i = 2; i < prices.size(); ++i){
        int curdif = prices[i] - minPrice;
        maxdif = std::max(curdif, maxdif);
        minPrice = std::min(minPrice, prices[i]);
    }

    return std::max(maxdif, 0);
}