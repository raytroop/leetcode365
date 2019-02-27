// https://leetcode.com/problems/linked-list-cycle-ii/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <unordered_set>
using std::unordered_set;

ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode*> viewed;
    while(head){
        if(viewed.count(head))
            return head;
        viewed.insert(head);
        head = head->next;
    }

    return nullptr;
}