// https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <algorithm>
#include <climits>
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// https://zxi.mytechroad.com/blog/tree/leetcode-124-binary-tree-maximum-path-sum/
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;

        int ans = INT_MIN;
        maxPathSum(root, ans);

        return ans;
    }
private:

    int maxPathSum(TreeNode* root, int& ans){
        if(!root)
            return 0;
        int l = std::max(0, maxPathSum(root->left, ans));
        int r = std::max(0, maxPathSum(root->right, ans));
        ans = std::max(l + r + root->val, ans);     // scan all nodes

        return std::max(l, r) + root->val;  // 1. root must be used     2. only one child branch can be used
    }
};