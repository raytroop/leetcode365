// https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <set>
using std::set;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode*> nodes;
    while(headA){
        nodes.insert(headA);
        headA = headA->next;
    }

    while(headB){
        if(nodes.count(headB))
            return headB;
        headB = headB->next;
    }

    return nullptr;
}
