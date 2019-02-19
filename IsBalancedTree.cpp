// https://leetcode.com/problems/balanced-binary-tree/
// Definition for a binary tree node.
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth;
        return isBalanced(root, &depth);
    }
private:
    bool isBalanced(TreeNode* root, int* pDepth){
        if(root == nullptr){
            *pDepth = 0;
            return true;
        }

        int LeftDepth, RightDepth;
        if(isBalanced(root->left, &LeftDepth) && isBalanced(root->right, &RightDepth) && std::abs(LeftDepth - RightDepth) < 2){
            *pDepth = std::max(LeftDepth, RightDepth) + 1;
            return true;
        }
        return false;
    }
};