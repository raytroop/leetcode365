// https://leetcode.com/problems/merge-two-binary-trees/


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return growTrees(t1, t2);
    }
private:
    TreeNode* growTrees(TreeNode* t1, TreeNode* t2){
        if(!t1 && !t2)
            return nullptr;

        int val = 0;
        TreeNode *t1l=nullptr, *t1r=nullptr, *t2l=nullptr, *t2r=nullptr;
        if(t1){
            val += t1->val;
            t1l = t1->left;
            t1r = t1->right;
        }
        if(t2){
            val += t2->val;
            t2l = t2->left;
            t2r = t2->right;
        }
        TreeNode* node = new TreeNode(val);
        node->left = growTrees(t1l, t2l);
        node->right = growTrees(t1r, t2r);
        return node;
    }
};