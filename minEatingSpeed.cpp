//https://leetcode.com/problems/koko-eating-bananas/
// https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-875-koko-eating-bananas/

// binary search
#include <vector>
#include <algorithm>
using std::vector;

int minEatingSpeed(vector<int>& piles, int H) {
    int r = *std::max_element(piles.cbegin(), piles.cend()) + 1;
    int l = 1;
    while(l < r){
        int mid = l + (r - l) / 2;
        int t = 0;
        for(auto x: piles)
            t += (x + mid - 1) / mid;
        if(t <= H)
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}