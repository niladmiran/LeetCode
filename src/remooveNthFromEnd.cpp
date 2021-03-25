//
// Created by jacob on 2021/3/25.
//

#include "ListNode.cpp"

// https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/603/


ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head->next == nullptr)  return nullptr;
    ListNode* slow = head, *fast = head;
    while (n--)
        fast = fast->next;
    while (fast && fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    if (slow == head && !fast)   return head->next;
    slow->next = slow->next->next;
    return head;
}