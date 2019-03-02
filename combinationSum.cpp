// https://leetcode.com/problems/combination-sum/

#include <vector>
#include <algorithm>
using std::vector;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n_ = candidates.size();
        std::sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> ans;
        dfs(curr, ans, target, candidates, 0);

        return ans;
    }
private:
    int n_;
    void dfs(vector<int>& curr, vector<vector<int>>& ans, int target, const vector<int>& candidates, int index){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(target < candidates[index])
            return;

        for(int i = index; i < n_; ++i){
            if(target < candidates[i])
                break;
            curr.push_back(candidates[i]);
            dfs(curr, ans, target - candidates[i], candidates, i);
            curr.pop_back();
        }
    }
};