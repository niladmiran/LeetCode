//
// Created by jacob on 2021/3/25.
//
#include <vector>

void rotate(std::vector<int>& nums, int k) {
    int sz = nums.size();
    k %= sz;
    for (int i = 0; i < sz - k ; ++i){
        nums.push_back(nums[0]);
        nums.erase(nums.begin());
    }
}