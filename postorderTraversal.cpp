// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
private:
    void traversal(TreeNode* root, vector<int>& ans){
        if(!root)
            return;
        traversal(root->left, ans);
        traversal(root->right, ans);
        ans.push_back(root->val);
    }
};
