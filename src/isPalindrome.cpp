//
// Created by jacob on 2021/3/25.
//

#include "ListNode.cpp"

// https://leetcode.com/explore/featured/card/top-interview-questions-easy/93/linked-list/772/


ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr, *cur = head, *nxt = head;
    while (nxt){
        nxt = nxt->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
} 

bool isPalindrome(ListNode* head) {
    if (head->next == nullptr)  return true;
    ListNode* slow = head,  *fast = head;
    while (fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    // reverse the second half part of the list
    slow->next = reverseList(slow->next);
    slow = slow->next;
    
    while (slow){
        if (slow->val != head->val) 
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}