//
// Created by jacob on 2021/3/31.
//
#include <queue>


class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


Node *connect(Node *root) {
    if (!root) return nullptr;
    std::queue<Node *> path;
    path.push(root);
    int curCount = 1, nextCount = 0;
    while (!path.empty()) {
        while (curCount--) {
            Node *temp = path.front();
            path.pop();
            if (curCount >= 1) {
                temp->next = path.front();
            } else {
                temp->next = nullptr;
            }
            if (temp->left) {
                path.push(temp->left);
                nextCount++;
            }
            if (temp->right) {
                path.push(temp->right);
                nextCount++;
            }
        }
        curCount = nextCount;
        nextCount = 0;
    }

    return root;
}