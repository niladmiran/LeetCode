//
// Created by jacob on 2021/3/25.
//

#include "ListNode.cpp"

// https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/560/


ListNode* reverseList(ListNode* head) {
    if (!head || !head->next)  return head;
    ListNode *cur = head, *prev = nullptr, *nxt = head;
    while (nxt){
        nxt = nxt->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}


// recursive way
ListNode* reverseList(ListNode* head, int k) {
    if (!head || !head->next)  return head;
    ListNode* newHead = reverseList(head->next, k);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}