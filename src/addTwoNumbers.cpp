//
// Created by jacob on 2021/4/2.
//
#include "ListNode.cpp"


ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode *dummyHead = new ListNode();
    ListNode *cur = dummyHead;
    while (l1 && l2) {
        cur->next = new ListNode((l1->val + l2->val + carry) % 10);
        cur = cur->next;
        carry = (l1->val + l2->val + carry) / 10;

        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        cur->next = new ListNode((l1->val + carry) % 10);
        cur = cur->next;
        carry = (l1->val + carry) / 10;

        l1 = l1->next;
    }
    while (l2) {
        cur->next = new ListNode((l2->val + carry) % 10);
        cur = cur->next;
        carry = (l2->val + carry) / 10;

        l2 = l2->next;
    }
    if (carry) cur->next = new ListNode(carry);

    return dummyHead->next;
}