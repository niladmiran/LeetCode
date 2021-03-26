//
// Created by jacob on 2021/3/26.
//
#include <vector>
#include "TreeNode.cpp"

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/631/

TreeNode* sortedArrayToBST(std::vector<int>& nums, int left, int right){
    if (left > right)   return nullptr;
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(nums, left, mid - 1);
    root->right = sortedArrayToBST(nums, mid + 1, right);

    return root;
}

TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    if (nums.empty())   return nullptr;
    int sz = nums.size();
    return sortedArrayToBST(nums, 0, sz - 1);
}