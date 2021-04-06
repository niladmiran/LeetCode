//
// Created by jacob on 2021/4/2.
//
#include "ListNode.cpp"

// https://leetcode.com/explore/learn/card/linked-list/219/classic-problems/1208/

ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next || !head->next->next) return head;
    int count = 1;
    ListNode *tail = head;
    while (tail->next) {
        tail = tail->next;
        count++;
    }
    ListNode *prev = nullptr, *cur = head;
    for (int i = 0; i < count; ++i) {
        if (i % 2) {
            tail->next = new ListNode(cur->val);
            tail = tail->next;
            prev->next = cur->next;
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}