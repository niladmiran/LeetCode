//
// Created by jacob on 2021/3/26.
//

#include <queue>
#include <algorithm> // max
#include "TreeNode.cpp"

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/94/trees/555/


int maxDepth(TreeNode* root) {
    if (!root)  return 0;
    else    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

// Nonrecursive way, use queue
int maxDepth(TreeNode* root, int k) {
    if (!root)  return 0;
    std::queue<TreeNode*> path;
    path.push(root);
    int count = 0;
    int curLayerNodes = 1;
    int nextLayerNodes;
    while (!path.empty()){
        nextLayerNodes = 0;
        for (int i = 0; i < curLayerNodes; ++i){
            TreeNode* temp = path.front();
            path.pop();
            if (temp->left){
                path.push(temp->left);
                nextLayerNodes++;
            }
            if (temp->right) {
                path.push(temp->right);
                nextLayerNodes++;
            }
        }
        curLayerNodes = nextLayerNodes;
        count++;
    }
    return count;
}
