// https://leetcode.com/problems/target-sum/
#include <vector>
#include <algorithm>
using std::vector;

// https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-494-target-sum/
// DFS
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        const int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum < std::abs(S)) return 0;
        int ans = 0;
        findTargetSumWays(nums, 0, S, ans);

        return ans;
    }
private:
    void findTargetSumWays(vector<int>& nums, int k, int S, int& ans){
        if(k == nums.size()){
            if(S == 0)
                ++ans;

            return;
        }

        findTargetSumWays(nums, k + 1, S - nums[k], ans);
        findTargetSumWays(nums, k + 1, S + nums[k], ans);
    }
};