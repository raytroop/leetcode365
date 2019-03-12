// https://leetcode.com/problems/combination-sum-ii/

#include <vector>
#include <algorithm>
using std::vector;

// http://zxi.mytechroad.com/blog/searching/leetcode-40-combination-sum-ii/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.empty())
            return {};
        std::sort(candidates.begin(), candidates.end());

        vector<int> curr;
        vector<vector<int>> ans;
        dfs(candidates, curr, ans, target, 0);

        return ans;
    }
private:
    void dfs(vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans, int target, int index){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = index; i < candidates.size(); ++i){
            if(candidates[i] > target)
                break;
            // Same number can be only used once at each depth.
            if(i > index && candidates[i] == candidates[i-1])
                continue;

            curr.push_back(candidates[i]);
            dfs(candidates, curr, ans, target - candidates[i], i + 1);
            curr.pop_back();
        }
    }
};