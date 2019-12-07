//https://leetcode.com/problems/binary-tree-right-side-view/

#include <vector>
#include <queue>
using std::vector;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        std::queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            const int n = q.size();
            TreeNode* curr;
            for (int i = 0; i < n; ++i) {
                curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            ans.push_back(curr->val);
        }

        return ans;
    }
};