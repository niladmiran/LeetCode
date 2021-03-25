//
// Created by jacob on 2021/3/25.
//
#include <vector>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/770/

void rotate(std::vector<std::vector<int> >& matrix) {
    int sz = matrix.size();
    int temp;
    for (int i = 0; i < (sz + 1) / 2; ++i){
        for (int j = 0; j < sz / 2; ++j){
            temp = matrix[i][j];
            matrix[i][j] = matrix[sz - 1 -j][i];
            matrix[sz - 1 -j][i] = matrix[sz - 1 -i][sz - 1 -j];
            matrix[sz - 1 -i][sz - 1 - j] = matrix[j][sz - 1 -i];
            matrix[j][sz - 1 - i] = temp;
        }
    }
}