//https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include <algorithm>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int minDepth(TreeNode* root) {
    if(root == nullptr)
        return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);

    if(root->left == nullptr)
        return r + 1;
    else if(root->right == nullptr)
        return l + 1;
    else
        return std::min(l, r) + 1;
}

