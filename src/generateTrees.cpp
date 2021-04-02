//
// Created by jacob on 2021/3/29.
//
#include <vector>
#include "TreeNode.cpp"

std::vector<TreeNode *> generateTrees(int left, int right) {
    if (left > right) return {nullptr};

    std::vector<TreeNode *> allTrees;
    for (int i = left; i <= right; ++i) {
        std::vector<TreeNode *> leftSubTrees = generateTrees(left, i - 1);
        std::vector<TreeNode *> rightSubTrees = generateTrees(i + 1, right);

        for (auto &leftTree: leftSubTrees) {
            for (auto &rightTree: rightSubTrees) {
                auto *root = new TreeNode(i);
                root->left = leftTree;
                root->right = rightTree;
                allTrees.push_back(root);
            }
        }
    }
    return allTrees;
}

std::vector<TreeNode *> generateTrees(int n) {
    if (n == 0) return {};
    return generateTrees(1, n);
}