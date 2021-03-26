//
// Created by jacob on 2021/3/26.
//
#include <vector>
#include <queue>
#include "TreeNode.cpp"


std::vector<std::vector<int> > levelOrder(TreeNode* root) {
    if (!root)  return {};

    std::vector<std::vector<int> > result;
    std::queue<TreeNode*> path;
    path.push(root);
    std::vector<int> cur;
    int curLayerNodes = 1;
    int nextLayerNodes;
    while (!path.empty()){
        cur.clear();
        nextLayerNodes = 0;
        for (int i = 0; i < curLayerNodes; ++i){
            TreeNode* temp = path.front();
            cur.push_back(temp->val);
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
        result.push_back(cur);
    }
    return result;
}