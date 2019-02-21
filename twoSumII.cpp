// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <vector>
using std::vector;

// https://zxi.mytechroad.com/blog/algorithms/binary-search/167-two-sum-ii-input-array-is-sorted/

// two pointer
vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;
    while(l < r){
        int sum = numbers[l] + numbers[r];
        if(sum == target)
            return {l+1, r+1};
        else if(sum < target)
            ++l;
        else
            --r;
    }

    return {};
}