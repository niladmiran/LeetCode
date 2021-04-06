//
// Created by jacob on 2021/4/2.
//
class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

// https://leetcode.com/explore/learn/card/linked-list/213/conclusion/1225/

Node *flatten(Node *head) {
    if (!head) return nullptr;
    Node *cur = head;

    while (cur) {
        Node *nxt = cur->next;
        if (cur->child) {
            Node *temp = cur->child;
            while (temp->next) temp = temp->next;
            cur->next = cur->child;
            cur->next->prev = cur;
            temp->next = nxt;
            // if the next pointer is not nullptr
            if (nxt)
                nxt->prev = temp;

            cur->child = nullptr;
        }
        cur = cur->next;
    }
    return head;
}