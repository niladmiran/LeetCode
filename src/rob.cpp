//
// Created by jacob on 2021/3/23.
//
#include <vector>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/97/dynamic-programming/576/

int rob(std::vector<int>& nums) {
    int sz = nums.size();
    if (sz == 1) return nums[0];
    if (sz == 2) return std::max(nums[0], nums[1]);
    std::vector<int> result(sz, 0);
    result[0] = nums[0];
    result[1] = std::max(nums[0], nums[1]);
    for (int i = 2; i < sz; ++i)
        result[i] = std::max(nums[i] + result[i - 2], result[i - 1]);

    int maxNum = 0;
    for (int i = 0; i < sz; ++i) maxNum = std::max(maxNum, result[i]);

    return maxNum;
}