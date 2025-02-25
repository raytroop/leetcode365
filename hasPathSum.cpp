//https://leetcode.com/problems/path-sum/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


bool hasPathSum(TreeNode* root, int sum) {
    if(root == nullptr)
        return false;

    if(root->left == nullptr && root->right == nullptr)
        return sum == root->val;

    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
}

