//
// Created by jacob on 2021/4/6.
//
#include <vector>
// https://leetcode.com/problems/unique-paths/submissions/


int uniquePaths(int m, int n) {
    std::vector<std::vector<int> > ans(m, std::vector<int>(n, 1));
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1];
        }
    }
    return ans[m - 1][n - 1];
}