//
// Created by jacob on 2021/3/31.
//
#include <vector>
#include <queue>
#include <stack>
#include "TreeNode.cpp"

// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
    if (!root) return {};
    std::stack<std::vector<int> > layers;
    std::vector<int> temp;
    std::queue<TreeNode *> path;
    path.push(root);
    int curCount = 1, nextCount = 0;
    while (!path.empty()) {
        temp.clear();
        while (curCount--) {
            TreeNode *curNode = path.front();
            temp.push_back(curNode->val);
            if (curNode->left) {
                path.push(curNode->left);
                nextCount++;
            }
            if (curNode->right) {
                path.push(curNode->right);
                nextCount++;
            }
            path.pop();
        }
        curCount = nextCount;
        nextCount = 0;
        layers.push(temp);
    }

    std::vector<std::vector<int> > ans;
    while (!layers.empty()) {
        ans.push_back(layers.top());
        layers.pop();
    }
    return ans;
}