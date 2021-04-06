//
// Created by jacob on 2021/4/6.
//
#include <vector>

// https://leetcode.com/problems/min-cost-climbing-stairs/submissions/

int minCostClimbingStairs(std::vector<int> &cost) {
    int sz = cost.size();
    std::vector<int> ans(sz, 1000000);
    ans[0] = cost[0], ans[1] = cost[1];
    for (int i = 2; i < sz; ++i) {
        ans[i] = std::min(ans[i - 1], ans[i - 2]) + cost[i];
    }
    return std::min(ans[sz - 1], ans[sz - 2]);
}