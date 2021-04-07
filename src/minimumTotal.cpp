//
// Created by jacob on 2021/4/7.
//
#include <vector>

int minimumTotal(std::vector<std::vector<int>> &triangle) {
    int height = triangle.size();
    // current state
    std::vector<int> dp(height, 10000000);
    // initialize the old state
    std::vector<int> old_dp(height, 0);
    old_dp[0] = triangle[0][0];
    for (int i = 1; i < height; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            if (j == 0)
                dp[j] = triangle[i][j] + old_dp[j];
            else if (j == i)
                dp[j] = triangle[i][j] + old_dp[j - 1];
            else
                dp[j] = triangle[i][j] + std::min(old_dp[j], old_dp[j - 1]);
        }
        // update the old state
        for (int j = 0; j < i + 1; ++j)
            old_dp[j] = dp[j];
    }
    int ans = old_dp[0];
    for (int i = 1; i < height; ++i) {
        if (old_dp[i] < ans) ans = old_dp[i];
    }
    return ans;
}