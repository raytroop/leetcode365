// https://leetcode.com/problems/permutations-ii/

#include <vector>
#include <algorithm>
using std::vector;

// https://zxi.mytechroad.com/blog/searching/leetcode-47-permutations-ii/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.empty())
            return {};
        nums_ = nums;
        std::sort(nums_.begin(), nums_.end());
        n_ = nums.size();

        vector<int> curr;
        vector<bool> used(n_, false);
        vector<vector<int>> ans;
        permuteUnique(curr, used, ans);

        return ans;
    }
private:
    int n_;
    vector<int> nums_;
    void permuteUnique(vector<int>& curr, vector<bool>& used, vector<vector<int>>& ans){
        if(curr.size() == n_){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < n_; ++i){
            if(used[i])
                continue;

            // Same number can be only used once at each depth.
            // `nums_[i] == nums_[i-1]`: same number
            // `!used[i-1]`: `nums_[i-1]` has NOT used in previous depth and can be used in ther current depth.
            if(i > 0 && nums_[i] == nums_[i-1] && !used[i-1])
                continue;

            used[i] = true;
            curr.push_back(nums_[i]);
            permuteUnique(curr, used, ans);
            used[i] = false;
            curr.pop_back();
        }
    }
};