//
// Created by jacob on 2021/3/13.
//

#include "../include/ListNode.h"

// construct a linked list from a vector
ListNode* ListNode::vectorToListNode(std::vector<int> nums){
    ListNode *dummyRoot = new ListNode(0);
    ListNode *ptr = dummyRoot;
    for (int item: nums) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

//void ListNode::insertLinkList(int val, ListNode **head){
//    if (*head == nullptr){
//        (*head)->val = val;
//        (*head)->next = nullptr;
//        return;
//    }
//
//}
