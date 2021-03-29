//
// Created by jacob on 2021/3/27.
//

#include "TreeNode.cpp"

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root)  return nullptr;
    if (root->val == val)   return root;
    if (root->val > val)    return searchBST(root->left, val);
    else    return searchBST(root->right, val);
}