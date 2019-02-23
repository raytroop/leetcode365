// https://leetcode.com/problems/validate-binary-search-tree/

#include <climits>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// https://zxi.mytechroad.com/blog/tree/leetcode-98-validate-binary-search-tree/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
private:
    bool isValidBST(TreeNode* root, long min_val, long max_val) {
        if (!root) return true;
        if (root->val <= min_val || root->val >= max_val)
            return false;
        return isValidBST(root->left, min_val, root->val)
            && isValidBST(root->right, root->val, max_val);
    }
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        prev_ = nullptr;
        return isValidBST(root);
    }
private:
    TreeNode* prev_;
    bool inorder(TreeNode* root){
        if(!root)
            return true;
        if(!inorder(root->left))
            return false;
        if(prev_ && root->val <= prev_->val)
            return false;
        prev_ = root;
        return inorder(root->right);
    }
};