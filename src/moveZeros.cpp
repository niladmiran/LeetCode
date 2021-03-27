//
// Created by jacob on 2021/3/26.
//
#include <vector>

void moveZeroes(std::vector<int> &nums) {
    int count = 0;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
        if (nums[i]) nums[count++] = nums[i];
    }
    while (count < sz)
        nums[count++] = 0;
}