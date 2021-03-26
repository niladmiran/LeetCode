//
// Created by jacob on 2021/3/26.
//
#include <vector>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/722/

int missingNumber(std::vector<int> &nums) {
    int ans = nums[0] ^0;
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        ans ^= i;
        ans ^= nums[i];
    }
    ans ^= n;
    return ans;
}