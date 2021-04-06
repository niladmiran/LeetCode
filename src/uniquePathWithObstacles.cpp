//
// Created by jacob on 2021/4/6.
//
#include <vector>

// https://leetcode.com/problems/unique-paths-ii/

int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    std::vector<std::vector<int> > ans(m, std::vector<int>(n, 0));
    // boundary condition
    for (int i = 0; i < m; ++i) {
        if (!obstacleGrid[i][0]) ans[i][0] = 1;
        else break;
    }
    for (int j = 0; j < n; ++j) {
        if (!obstacleGrid[0][j]) ans[0][j] = 1;
        else break;
    }
    // find path
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j]) ans[i][j] = 0;
            else ans[i][j] = ans[i][j - 1] + ans[i - 1][j];
        }
    }

    return ans[m - 1][n - 1];
}