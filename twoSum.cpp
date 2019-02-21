//https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;

// https://zxi.mytechroad.com/blog/hashtable/leetcode-1-two-sum/
vector<int> twoSum(vector<int>& nums, int target) {
    const int n = nums.size();
    unordered_map<int, int> indices;

    for(int i = 0; i < n; ++i)
        indices[nums[i]] = i;

    for(int i = 0; i < n; ++i){
        int left = target - nums[i];
        if(indices.count(left) && indices[left] != i)
            return {i, indices[left]};
    }

    return {};
}