//
// Created by jacob on 2021/3/26.
//

#include "TreeNode.cpp"

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/627/

// recursive implementation
bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode){
    if (!leftNode && !rightNode)    return true;
    if (!leftNode || !rightNode)    return false;
    return (leftNode->val == rightNode->val) &&
           isSymmetric(leftNode->left, rightNode->right)
           && isSymmetric(leftNode->right, rightNode->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root)  return true;
    return isSymmetric(root->left, root->right);
}