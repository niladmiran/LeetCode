//
// Created by jacob on 2021/3/24.
//
#include <vector>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/564/

int maxProfit(std::vector<int>& prices) {
    int maxprofit = 0;
    int sz = prices.size();
    int curPrice = prices[0];
    for (int i = 0; i < sz; ++i){
        // greedy method, if the cost is lower than current price, sell it and buy it again
        if (prices[i] > curPrice)
            maxprofit += prices[i] - curPrice;
        curPrice = prices[i];
    }
    return maxprofit;
}