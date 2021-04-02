//
// Created by jacob on 2021/4/2.
//

// https://leetcode.com/explore/learn/card/linked-list/214/two-pointer-technique/1215/

#include "ListNode.cpp"

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int szA = 0, szB = 0;
    ListNode *ptrA = headA, *ptrB = headB;
    // compute the size of A and B
    while (ptrA) {
        ptrA = ptrA->next;
        szA++;
    }
    while (ptrB) {
        ptrB = ptrB->next;
        szB++;
    }
    // align the A and B
    ptrA = headA, ptrB = headB;
    while (szA > szB) {
        ptrA = ptrA->next;
        szA--;
    }
    while (szA < szB) {
        ptrB = ptrB->next;
        szB--;
    }
    // check validity of the listnode
    if (!szA || !szB) return nullptr;
    // find the intersection.
    while (ptrA && ptrB && ptrA != ptrB) {
        ptrA = ptrA->next;
        ptrB = ptrB->next;
    }
    if (ptrA && ptrB) return ptrA;
    return nullptr;
}