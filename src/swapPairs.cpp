//
// Created by jacob on 2021/3/27.
//
#include "ListNode.cpp"

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next)  return head;
    int temp = head->val;
    head->val = head->next->val;
    head->next->val = temp;
    head->next->next = swapPairs(head->next->next);
    return head;
}
