//
// Created by jacob on 2021/3/23.
//
#include <vector>

// https://leetcode.com/explore/featured/card/top-interview-questions-easy/97/dynamic-programming/569/
// Climbing stairs
int climbStairs(int n) {
    std::vector<int> result(2, 1);
    int temp;
    for (int i = 1; i < n; ++i){
        temp = result[0] + result[1];
        result[0] = result[1];
        result[1] = temp;
    }
    return result[1];
}

