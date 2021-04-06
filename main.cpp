// maze problem
// http://poj.org/problem?id=3984

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *prev;
        ListNode *next;

        ListNode() : val(0), prev(nullptr), next(nullptr) {}

        ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}

        ListNode(int x, ListNode *prevNode, ListNode *nextNode) : val(x), prev(prevNode), next(nextNode) {}
    };


    /** Initialize your data structure here. */
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode *cur = head;
        while (cur && index--) cur = cur->next;
        if (!cur) return -1;
        return cur->val;

    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if (!head) {
            head = new ListNode(val, nullptr, tail);
            return;
        }
        ListNode *temp = new ListNode(val, nullptr, head);
        head->prev = temp;
        tail = head;
        head = temp;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!head) {
            head = new ListNode(val, nullptr, tail);
            return;
        }
        if (!tail) {
            tail = new ListNode(val, head, nullptr);
            head->next = tail;
            return;
        }
        tail->next = new ListNode(val, tail, nullptr);
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index < 0) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        ListNode *cur = head;
        while (cur && index--) {
            cur = cur->next;
        }
        // invalid index
        if (!cur && index) return;

        cur->prev = new ListNode(val, cur->prev, cur);
        cur->prev->prev->next = cur->prev;

    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0) return;
        if (index == 0) {
            ListNode *temp = head;
            head = head->next;
            head->prev = nullptr;

            delete temp;
        }
        ListNode *cur = head;
        while (cur && index--) {
            cur = cur->next;
        }
        if (!cur && index) return;

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        delete cur;

    }

private:
    ListNode *head;
    ListNode *tail;
};

int main(int argc, char const *argv[]) {
    MyLinkedList *head = new MyLinkedList();
    head->addAtHead(1);
    head->deleteAtIndex(0);    // now the linked list is 1->3
    return 0;
}
