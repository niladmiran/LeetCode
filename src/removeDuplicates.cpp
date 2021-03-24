//
// Created by jacob on 2021/3/24.
//
#include <vector>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/727/

int removeDuplicates(std::vector<int>& nums) {
    int sz = nums.size();
    if (sz == 0)    return 0;
    int left = 0, right = 0;
    for (int i = 0; i < sz; ++i){
        // if the current element is equal to previous unique element, skip it
        if (nums[right] == nums[left])
            right++;
        // otherwise, we swap the current unique element, and update the previous unique element
        else
            nums[++left] = nums[right++];
    }
    return left + 1;
}