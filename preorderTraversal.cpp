// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include <vector>
using std::vector;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
private:
    void traversal(TreeNode* root, vector<int>& ans){
        if(!root)
            return;
        ans.push_back(root->val);
        traversal(root->left, ans);
        traversal(root->right, ans);
    }
};