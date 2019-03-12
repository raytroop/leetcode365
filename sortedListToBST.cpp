// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/solution/
// Approach 1: Recursion
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
            // If the head doesn't exist, then the linked list is empty
        if (head == nullptr) {
            return nullptr;
        }

        // Find the middle element for the list.
        ListNode* mid = findMiddleElement(head);

        // The mid becomes the root of the BST.
        TreeNode* node = new TreeNode(mid->val);

        // Base case when there is just one element in the linked list
        if (head == mid) {
            return node;
        }

        // Recursively form balanced BSTs using the left and right halves of the original list.
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid->next);

        return node;
    }
private:
    ListNode* findMiddleElement(ListNode* head) {

        // The pointer used to disconnect the left half from the mid node.
        ListNode* prevPtr = nullptr;
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;

        // Iterate until fastPr doesn't reach the end of the linked list.
        while (fastPtr != nullptr && fastPtr->next != nullptr) {
            prevPtr = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        // Handling the case when slowPtr was equal to head.
        if (prevPtr != nullptr) {
            prevPtr->next = nullptr;
        }

        return slowPtr;
  }
};

