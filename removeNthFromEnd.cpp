// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd2(ListNode* head, int n) {
    ListNode* dmy = new ListNode(-1);
    dmy->next = head;
    ListNode *p1 = dmy, *p2 = dmy;
    for (int i = 0; i < n; ++i)
        p2 = p2->next;

    while (p2->next)
    {
        p2 = p2->next;
        p1 = p1->next;
    }

    p2 = p1->next;
    p1->next = p2->next;
    delete p2;

    head = dmy->next;
    delete dmy;

    return head;
}

// https://zxi.mytechroad.com/blog/list/leetcode-19-remove-nth-node-from-end-of-list/
ListNode* removeNthFromEnd(ListNode* head, int n) {
    int l = 0;
    ListNode* cur = head;
    while(cur){
        ++l;
        cur = cur->next;
    }
    if(l == n){
        ListNode* ans = head->next;
        delete head;
        return ans;
    }

    l -= n;
    cur = head;
    while(--l)
        cur = cur->next;
    ListNode* node2del = cur->next;
    cur->next = node2del->next;
    delete node2del;

    return head;
}
