// https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
private:
    void traversal(TreeNode* root, vector<int>& ans){
        if(!root)
            return;
        ans.push_back(root->val);
        traversal(root->left, ans);
        traversal(root->right, ans);
    }
};


// 迭代实现 前序遍历
#include <stack>
using std::stack;

vector<int> preorderTraversal(TreeNode* root) {
    if(!root)
        return {};
    vector<int> ans;
    stack<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.top();
        q.pop();
        ans.push_back(node->val);
        if(node->right)
            q.push(node->right);
        if(node->left)
            q.push(node->left);
    }

    return ans;
}