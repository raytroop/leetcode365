// https://leetcode.com/problems/path-sum-ii/

#include <vector>
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> curr;
        pathSum(root, sum, curr, ans);

        return ans;
    }
private:
    void pathSum(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ans){
        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr){
            if(sum == root->val){
                curr.push_back(root->val);
                ans.push_back(curr);
                curr.pop_back();
            }

            return;
        }

        curr.push_back(root->val);
        pathSum(root->left, sum - root->val, curr, ans);
        pathSum(root->right, sum - root->val, curr, ans);
        curr.pop_back();
        return;
    }
};