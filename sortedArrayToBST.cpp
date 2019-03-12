// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int l, int r){
        if(l == r)
            return nullptr;
        int mid = l + (r - l)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, l, mid);
        node->right = sortedArrayToBST(nums, mid+1, r);
        return node;
    }
};