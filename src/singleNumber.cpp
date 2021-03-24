//
// Created by jacob on 2021/3/24.
//
#include <vector>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/

int singleNumber(std::vector<int>& nums) {
    int sz = nums.size();
    if (sz == 1)    return nums[0];
    int ans = nums[0];
    for (int i = 1; i < sz; ++i)    ans ^= nums[i];
    return ans;
}