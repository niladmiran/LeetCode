//
// Created by jacob on 2021/3/31.
//

#include <queue>
#include "TreeNode.cpp"

// https://leetcode.com/problems/minimum-depth-of-binary-tree/
int minDepth(TreeNode *root) {
    if (!root) return 0;
    std::queue<TreeNode *> path;
    path.push(root);
    int curCount = 1, nextCount = 0;
    int depth = 1;
    while (!path.empty()) {
        while (curCount--) {
            TreeNode *temp = path.front();
            if (!temp->left && !temp->right)
                return depth;
            if (temp->left) {
                path.push(temp->left);
                nextCount++;
            }
            if (temp->right) {
                path.push(temp->right);
                nextCount++;
            }
            path.pop();
        }
        depth++;
        curCount = nextCount;
        nextCount = 0;
    }
    return depth;
}
