//
// Created by jacob on 2021/3/24.
//
#include <vector>
#include <map>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> ans;
    std::vector<int> result;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i){
        if (ans.find(nums[i]) == ans.end())
            ans[target - nums[i]] = i;
        else{
            result.push_back(ans[nums[i]]);
            result.push_back(i);
        } 
    }
    return result;
}
