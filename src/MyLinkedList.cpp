// https://leetcode.com/explore/learn/card/linked-list/209/singly-linked-list/1290/

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode *next;

        ListNode(int x = 0) : val(x), next(nullptr) {}

        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    
    /** Initialize your data structure here. */
    MyLinkedList(): head(nullptr){}
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        ListNode* cur = head;
        while (cur && index--) cur = cur->next;
        if (cur == nullptr) return -1;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val, head);
        head = newHead;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (!head)  {
            head = new ListNode(val);
            return;
        }
        ListNode* cur = head;
        while (cur->next)   cur = cur->next;
        cur->next = new ListNode(val);
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        ListNode* cur = head, *prev = nullptr;
        while (cur && index--){
            prev = cur;
            cur = cur->next;
        }
        // index = 0
        if (prev == nullptr){
            addAtHead(val);
            return;
        }

        // invalid index
        if (index && cur == nullptr)  return;
        ListNode* temp = new ListNode(val, cur);
        prev->next = temp;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        ListNode* cur = head, *prev = nullptr;
        while (cur && index--){
            prev = cur;
            cur = cur->next;
        }
        // delete head
        if (prev == nullptr){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        // invalid index
        if (cur == nullptr)  
            return;
        ListNode* temp = cur;
        
        prev->next = cur->next;
        delete temp;
    }
    
private:
    ListNode* head;
};