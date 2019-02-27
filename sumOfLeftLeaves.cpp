// https://leetcode.com/problems/sum-of-left-leaves/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sum(root, ans);
        return ans;
    }
private:
    void sum(TreeNode* root, int& ans){
        if(!root)
            return;
        if(root->left && !root->left->left && !root->left->right){
            ans += root->left->val;
            sum(root->right, ans);
        }
        else{
            sum(root->left, ans);
            sum(root->right, ans);
        }
    }
};



/* //https://zxi.mytechroad.com/blog/tree/leetcode-404-sum-of-left-leaves/

int sumOfLeftLeaves(TreeNode* root){
    if(!root)
        return 0;
    // find left leave
    if(root->left && !root->left->left && !root->left->right)
        return (root->left->val) + sumOfLeftLeaves(root->right);
    // Recursion
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
} */