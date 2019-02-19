// *
//  * Definition for a binary tree node.
#include <vector>
#include <queue>
using std::queue;
using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<double> ans;
        while(! q.empty()){
            int n = q.size();
            double sum = 0;
            for(int i = 0; i < n; ++i){
                TreeNode* node = q.front();
                sum += static_cast<double>(node->val);
                q.pop();
                if(node->left != nullptr)
                    q.push(node->left);
                if(node->right != nullptr)
                    q.push(node->right);
            }
            ans.push_back(sum / n);
        }
        return ans;
    }
};