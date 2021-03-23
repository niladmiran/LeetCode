//
// Created by jacob on 2021/3/23.
//
#include <vector>

// https://leetcode.com/explore/featured/card/top-interview-questions-easy/97/dynamic-programming/572/
// maxProfit

int maxProfit(std::vector<int>& prices) {
    int sz = prices.size();
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 0; i < sz; ++i){
        minPrice = std::min(prices[i], minPrice);
        maxProfit = std::max(prices[i] - minPrice, maxProfit);
    }
    return maxProfit;
}