#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <string>

#include "ListNode.h"
#include "TreeNode.h"

class Solution
{
public:
    // LeetCode 322, Coin Change
    // https://leetcode.com/problems/coin-change/
    int coinChange(std::vector<int> &coins, int amount);

    // LeetCode 61, rotate list
    // https://leetcode.com/problems/rotate-list/
    ListNode* rotateRight(ListNode* head, int k);

    // LeetCode 324, wiggle sort II
    // https://leetcode.com/problems/wiggle-sort-ii/
    void wiggleSort(std::vector<int>& nums);

    // LeetCode 98, Validate Binary Search Tree
    // https://leetcode.com/problems/validate-binary-search-tree/
    bool isValidBST(TreeNode* root);

    // HackerRank, Left Rotation
    // https://www.hackerrank.com/challenges/array-left-rotation/problem
    std::vector<int> rotateLeft(int d, std::vector<int> arr);

    // LeetCode 300, Longest Increasing Subsequence
    // https://leetcode.com/problems/longest-increasing-subsequence/
    int lengthOfLIS(std::vector<int>& nums);

    // HackerRank, Pangrams
    // https://www.hackerrank.com/challenges/pangrams/problem
    std::string pangrams(std::string s);

    // mooc, special password lock
    // http://cxsjsxmooc.openjudge.cn/2021t2springall/001/
    int passwordLock(std::string & initial, std::string & goal);

    // LeetCode 91, Reverse Linked List
    // https://leetcode.com/problems/reverse-linked-list/
    ListNode* reverseList(ListNode* head);

    // LeetCOde, Valid Parentheses
    // https://leetcode.com/problems/valid-parentheses/
    bool isValid(std::string s);

    // LeetCode Merge Two Sorted Lists
    // https://leetcode.com/problems/merge-two-sorted-lists/
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    // LeetCode 88, Merge Sorted Array
    // https://leetcode.com/problems/merge-sorted-array/
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);

    // LeetCode 215, Kth Largest Element in an Array
    // https://leetcode.com/problems/kth-largest-element-in-an-array/
    int findKthLargest(std::vector<int>& nums, int k);

    // LeetCode 121. Best Time to Buy and Sell Stock
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    int maxProfit(std::vector<int>& prices);

    // LeetCode 226, Invert Binary Tree
    // https://leetcode.com/problems/invert-binary-tree/
    TreeNode* invertTree(TreeNode* root);

    // LeetCode 92, Reverse Linked List II
    // https://leetcode.com/problems/reverse-linked-list-ii/
    ListNode* reverseK(ListNode* head, int k);
    ListNode* reverseBetween(ListNode* head, int left, int right);

    int getNumberOfBackOrders(std::vector<std::vector<int> >& orders);

    int maxValue(int n, int index, int maxSum);

    // LeetCode 7, Reverse Integer
    // https://leetcode.com/problems/reverse-integer/
    int reverse(int x);
};

#endif // SOLUTION_H
