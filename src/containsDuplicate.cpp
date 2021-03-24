//
// Created by jacob on 2021/3/24.
//
#include <vector>
#include <map>
#include <set>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/578/

bool containsDuplicate(std::vector<int>& nums) {
    std::map<int, int> count;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i){
        count[nums[i]]++;
        if (count[nums[i]] == 2)    return true;
    }
    return false;
}

bool containsDuplicate(std::vector<int>& nums, int k) {
    std::set<int> seen; 
    
    for (auto x : nums) {
        if (seen.find(x) != seen.end()) {
            return true; 
        }
        seen.insert(x); 
    }
    return false; 
}