//
// Created by jacob on 2021/4/6.
//
#include <vector>

// https://leetcode.com/problems/minimum-path-sum/submissions/

int minPathSum(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    std::vector<std::vector<int> > ans(m, std::vector<int>(n, 10000000));
    ans[0][0] = grid[0][0];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0)
                ans[i][j] = std::min(ans[i][j], ans[i - 1][j] + grid[i][j]);
            if (j > 0)
                ans[i][j] = std::min(ans[i][j], ans[i][j - 1] + grid[i][j]);
        }
    }
    return ans[m - 1][n - 1];
}