//https://leetcode.com/problems/maximum-depth-of-binary-tree/


#include <algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if(root == nullptr)
        return 0;

    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
