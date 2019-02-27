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
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mergeTwoLists(sortList(head), sortList(mid));
    }
private:
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