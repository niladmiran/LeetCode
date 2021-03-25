//
// Created by jacob on 2021/3/24.
//

#include "ListNode.cpp"


bool hasCycle(ListNode *head) {
    if (!head || !head->next)   return false;
    ListNode* slow = head, *fast = head;
    while (fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)   return true;
    }
    return false;
}