//
// Created by jacob on 2021/3/26.
//

#include <vector>
#include "TreeNode.cpp"

void MidOrder(TreeNode* root, std::vector<int>& vals){
    if (root != nullptr){
        MidOrder(root->left, vals);
        vals.push_back(root->val);
        MidOrder(root->right, vals);
    }
}

bool isValidBST(TreeNode* root){
    std::vector<int> vals;
    MidOrder(root, vals);
    int nums_nodes = vals.size();
    for (int i = 0; i < nums_nodes - 1; ++i){
        if (vals[i] >= vals[i + 1])
            return false;
    }
    return true;
}