// https://leetcode.com/problems/combinations/

#include <vector>
using std::vector;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        n_ = n;
        k_ = k;
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(curr, ans, 1);

        return ans;
    }
private:
    int n_;
    int k_;
    void dfs(vector<int>& curr, vector<vector<int>>& ans, int s){
        if(curr.size() == k_)
            ans.push_back(curr);

        for(int i = s; i <= n_; ++i){
            curr.push_back(i);
            dfs(curr, ans, i + 1);
            curr.pop_back();
        }
    }
};