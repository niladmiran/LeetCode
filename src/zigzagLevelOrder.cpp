//
// Created by jacob on 2021/3/31.
//
#include <vector>
#include <deque>
#include "TreeNode.cpp"

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) return {};
    bool leftToRight = true;
    int curCount = 1;
    std::deque<TreeNode *> nodesQue = {root};
    int nextCount = 0;
    std::vector<std::vector<int> > ans;
    std::vector<int> layer;
    while (!nodesQue.empty()) {
        layer.clear();
        if (leftToRight) {
            while (curCount--) {
                TreeNode *temp = nodesQue.front();
                layer.push_back(temp->val);
                if (temp->left) {
                    nodesQue.push_back(temp->left);
                    nextCount++;
                }
                if (temp->right) {
                    nodesQue.push_back(temp->right);
                    nextCount++;
                }
                nodesQue.pop_front();
            }
            leftToRight = !leftToRight;

        } else {// right to left
            while (curCount--) {
                TreeNode *temp = nodesQue.back();
                layer.push_back(temp->val);
                if (temp->right) {
                    nodesQue.push_front(temp->right);
                    nextCount++;
                }
                if (temp->left) {
                    nodesQue.push_front(temp->left);
                    nextCount++;
                }
                nodesQue.pop_back();
            }
            leftToRight = !leftToRight;
        }
        ans.push_back(layer);
        curCount = nextCount;
        nextCount = 0;
    }

    return ans;
}