//
// Created by jacob on 2021/4/2.
//

// https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1214/

#include "ListNode.cpp"


ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next || !head->next->next) return nullptr;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) break;
    }
    if (slow != fast) return nullptr;
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}