// https://leetcode.com/problems/reorder-list/

#include <vector>
using std::vector;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

void reorderList(ListNode* head) {
    vector<ListNode*> seq;
    ListNode* prev = head;
    while (prev) {
        seq.push_back(prev);
        prev = prev->next;
    }

    const int n = seq.size();
    prev = new ListNode(-1);
    for (int i = 0; i < n / 2; ++i) {
        prev->next = seq[i];
        prev = seq[n - 1 - i];
        seq[i]->next = prev;
    }

    if (n % 2 == 0)
        prev->next = nullptr;
    else {
        prev->next = seq[n / 2];
        seq[n / 2]->next = nullptr;
    }
}