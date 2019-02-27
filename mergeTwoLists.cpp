// https://leetcode.com/problems/merge-two-sorted-lists/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1)
        return l2;
    if(!l2)
        return l1;

    ListNode* head;
    if(l1->val < l2->val){
        head = l1;
        l1 = l1 ->next;
    }
    else{
        head = l2;
        l2 = l2->next;
    }
    ListNode* prev = head;
    while(l1 && l2)
        if(l1->val < l2->val){
            prev->next = l1;
            prev = l1;
            l1 = l1->next;
        }
        else{
            prev->next = l2;
            prev = l2;
            l2 = l2->next;
        }

        prev->next = l1 ? l1 : l2;

    return head;
}

// https://zxi.mytechroad.com/blog/leetcode/leetcode-21-merge-two-sorted-lists/
/*
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
*/