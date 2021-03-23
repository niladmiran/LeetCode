#ifndef LINKLIST_H
#define LINKLIST_H

#include <vector>

class ListNode
{
public:
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode* vectorToListNode(std::vector<int> nums);

    friend class Solution;

//    void insertLinkList(int val, ListNode **head);

    // operation of linklist

private:
    int val;
    ListNode *next;
};

#endif // LINKLIST_H
