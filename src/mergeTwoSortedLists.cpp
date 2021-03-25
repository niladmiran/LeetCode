//
// Created by jacob on 2021/3/24.
//

#include "ListNode.cpp"

// https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/771/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    while (l1 && l2){
        if (l1->val < l2->val){
            cur->next = l1;
            cur = l1;
            l1 = l1->next;
        }else{
            cur->next = l2;
            cur = l2;
            l2 = l2->next;
        }
    }
    while (l1){
        cur->next = l1;
        cur = l1;
        l1 = l1->next;
    }
    while (l2){
        cur->next = l2;
        cur = l2;
        l2 = l2->next;
    }
    return dummyHead->next;
}