//https://leetcode.com/problems/reverse-linked-list/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    while(!head){
        ListNode* tmp = head->next;
        head->next = prev;
        prev = head;
        head = tmp;
    }

    return prev;
}
