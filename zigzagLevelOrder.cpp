//https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


#include <vector>
#include <queue>
#include <algorithm>
using std::vector;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};

        std::queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int d = 0;
        while (!q.empty()) {
            int n = q.size();
            vector<int> curr;
            for (int i = 0; i < n; ++i) {
                TreeNode* node = q.front();
                q.pop();
                curr.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (d%2) std::reverse(curr.begin(), curr.end());
            ans.push_back(curr);
            ++d;
        }

        return ans;
    }
};
