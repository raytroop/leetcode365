// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        int curr = 0;
        sumNumbers(root, curr, ans);

        return ans;
    }
private:
    void sumNumbers(TreeNode* root, int curr, int& ans){
        if(root == nullptr)
            return;

        int tmp = curr * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            ans += tmp;
            return;
        }

        sumNumbers(root->left, tmp, ans);
        sumNumbers(root->right, tmp, ans);
    }
};