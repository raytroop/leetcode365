// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traversal(root, ans);
        return ans;
    }
private:
    void traversal(TreeNode* root, vector<int>& ans){
        if(!root)
            return;
        traversal(root->left, ans);
        ans.push_back(root->val);
        traversal(root->right, ans);
    }
};


// 迭代实现 中序遍历
#include <stack>
using std::stack;

class Solution_2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        goAlongLeftBranch(root, s);
        while(!s.empty()){
            TreeNode* node = s.top();
            s.pop();
            ans.push_back(node->val);
            goAlongLeftBranch(node->right, s);
        }

        return ans;
    }
private:
    void goAlongLeftBranch(TreeNode* root, stack<TreeNode*>& s){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
};