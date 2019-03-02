// https://leetcode.com/problems/invert-binary-tree/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* invertTree(TreeNode* root) {
    if(!root)
        return root;
    TreeNode* left = root->left;
    TreeNode* right = root->right;

    root->left = invertTree(right);
    root->right = invertTree(left);

    return root;
}
