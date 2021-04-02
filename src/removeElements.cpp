//
// Created by jacob on 2021/4/2.
//
#include "ListNode.cpp"

// https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1207/

ListNode *removeElements(ListNode *head, int val) {
    while (head && head->val == val) head = head->next;
    if (!head) return nullptr;
    ListNode *cur = head->next, *prev = head;
    while (cur) {
        if (cur->val == val) {
            prev->next = cur->next;
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}