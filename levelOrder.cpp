// https://leetcode.com/problems/binary-tree-level-order-traversal/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#include <vector>
#include <queue>
using std::queue;
using std::vector;


vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root)
        return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty()){
        vector<int> curr;
        const int sz = q.size();
        for(int i = 0; i < sz; ++i){
            TreeNode* node = q.front(); q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            curr.push_back(node->val);
        }
        ans.push_back(curr);
    }
    return ans;
}
