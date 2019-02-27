// https://leetcode.com/problems/linked-list-cycle/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#include <unordered_set>
using std::unordered_set;

// https://zxi.mytechroad.com/blog/list/leetcode-141-linked-list-cycle/
// HashTable
bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> viewed;
    while(head){
        if(viewed.count(head))
            return true;
        viewed.insert(head);
        head = head->next;
    }

    return false;
}

// Fast + Slow pointers
// Author: Huahua
// Running time: 8 ms
class Solution {
public:
  bool hasCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (fast) {
      if (!fast->next) return false;
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) return true;
    }
    return false;
  }
};
