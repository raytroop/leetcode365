#include <vector>
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
    TreeNode* createBST(vector<int> nums) {
        TreeNode* root = nullptr;
        for(auto num: nums)
            root = insert(root, num);

        return root;
    }
private:
    TreeNode* insert(TreeNode* root, int val){
        if(root == nullptr)
            return new TreeNode(val);

        if(val <= root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);

        return root;
    }
};