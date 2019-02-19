//https://leetcode.com/problems/maximum-product-subarray/
#include <vector>
#include <algorithm>
using std::vector;

int maxProduct(vector<int>& nums) {
    const int sz = nums.size();
    vector<int> maxVals(sz);
    vector<int> minVals(sz);
    maxVals[0] = nums[0];
    minVals[0] = nums[0];
    int max_ = nums[0];

    for(int i = 1; i < sz; ++i){
        int cur = nums[i];
        if(cur >= 0){
            maxVals[i] = std::max(maxVals[i-1] * cur, cur);
            minVals[i] = std::min(minVals[i-1] * cur, cur);
        }
        else{
            maxVals[i] = std::max(minVals[i-1] * cur, cur);
            minVals[i] = std::min(maxVals[i-1] * cur, cur);
        }
        max_ = std::max(maxVals[i], max_);
    }

    return max_;
}