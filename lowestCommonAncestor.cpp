// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/solution/
// Approach 1: Recursive Approach

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Traverse the tree
        recurseTree(root, p, q);
        return ans;
    }

private:
    TreeNode* ans = nullptr;

    bool recurseTree(TreeNode* currentNode, TreeNode* p, TreeNode* q) {

        // If reached the end of a branch, return false.
        if (currentNode == nullptr) {
            return false;
        }

        // Left Recursion. If left recursion returns true, set left = 1 else 0
        int left = recurseTree(currentNode->left, p, q) ? 1 : 0;

        // Right Recursion
        int right = recurseTree(currentNode->right, p, q) ? 1 : 0;

        // If the current node is one of p or q
        int mid = (currentNode == p || currentNode == q) ? 1 : 0;


        // If any two of the flags left, right or mid become True
        if (mid + left + right >= 2) {
            ans = currentNode;
        }

        // Return true if any one of the three bool values is True.
        return (mid + left + right > 0);
    }
};