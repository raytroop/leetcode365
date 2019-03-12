//https://leetcode.com/problems/sort-list/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // 0 or 1 element, we are done.
        if(!head || !head->next)
            return head;

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(prev)
            prev->next = nullptr;
        return mergeTwoLists(sortList(head), sortList(slow));
    }
private:
    // https://zxi.mytechroad.com/blog/leetcode/leetcode-21-merge-two-sorted-lists/
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy = ListNode(0);
        ListNode* tail = &dummy;
        while (l1 && l2){
            if(l1->val < l2->val){
                tail->next = l1;
                l1 = l1->next;
            } else{
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

#include <vector>
using std::vector;

ListNode* createList(vector<int> nums){
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for(int x: nums){
        tail->next = new ListNode(x);
        tail = tail->next;
    }

    return dummy.next;
}
int main(){
    ListNode* head = createList({4,2,1,3});
    Solution sol;
    sol.sortList(head);
}