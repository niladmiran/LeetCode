//
// Created by jacob on 2021/4/7.
//
#include <vector>
// https://leetcode.com/problems/remove-element/submissions/

int removeElement(std::vector<int> &nums, int val) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        while (left <= right && nums[left] != val)
            left++;
        while (right >= left && nums[right] == val) {
            right--;
            nums.pop_back();
        }
        if (left < nums.size() && nums[left] == val) {
            nums[left] = nums[right];
            left++, right--;
            nums.pop_back();
        }
    }
    return nums.size();
}
