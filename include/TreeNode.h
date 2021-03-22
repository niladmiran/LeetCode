#ifndef TREENODE_H
#define TREENODE_H

#include <vector>

class TreeNode
{
public:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    friend class Solution;
    friend void MidOrder(TreeNode* root, std::vector<int>& vals);

private:
    int val;
    TreeNode *left;
    TreeNode *right;
};

#endif // TREENODE_H
