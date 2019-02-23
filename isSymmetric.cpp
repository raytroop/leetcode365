//https://leetcode.com/problems/symmetric-tree/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// https://zxi.mytechroad.com/blog/tree/leetcode-101-symmetric-tree/
// Recursion
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
private:
    bool isMirror(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)
            return true;
        if(!root1 || !root2)
            return false;

        return (root1->val == root2->val) && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
    }
};


// BFS
#include <vector>
#include <queue>
#include <climits>
using std::queue;
using std::vector;

bool isSymmetric(TreeNode* root){
    queue<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        const int n = s.size();
        vector<int> curr;
        for(int i = 0; i < n; ++i){
            TreeNode* node = s.front();
            s.pop();

            if(node == nullptr)
                curr.push_back(INT_MAX);
            else{
                s.push(node->left);
                s.push(node->right);
                curr.push_back(node->val);
            }
        }

        for(int i = 0; i < n/2; ++i){
            if(curr[i] != curr[n-1-i])
                return false;
        }
    }

    return true;
}
