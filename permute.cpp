// https://leetcode.com/problems/permutations/

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        n_ = nums.size();
        vector<int> curr;
        vector<vector<int>> ans;
        vector<int> used(n_, false);
        dfs(curr, ans, nums, used);

        return ans;
    }
private:
    int n_;
    void dfs(vector<int>& curr, vector<vector<int>>& ans, vector<int>& nums, vector<int>& used){
        if(curr.size() == n_){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < n_; ++i){
            if(used[i])
                continue;

            curr.push_back(nums[i]);
            used[i] = true;
            dfs(curr, ans, nums, used);
            curr.pop_back();
            used[i] = false;
        }
    }
};