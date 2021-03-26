//
// Created by jacob on 2021/3/25.
//

#include "ListNode.cpp"

void deleteNode(ListNode* node) {
    ListNode* prev;
    int temp = 0;
    while (node->next){
        node->val = node->next->val;
        prev = node;
        node = node->next;
    }
    prev->next = nullptr;
}