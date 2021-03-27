//
// Created by jacob on 2021/3/26.
//

#include <vector>

std::vector<std::vector<int> > generate(int numRows) {
    std::vector<std::vector<int> > result;
    int sz = 1;
    std::vector<int> temp = {1};
    result.push_back(temp);
    for (int i = 1; i < numRows; ++i) {
        temp.clear();

        temp.push_back(1);

        for (int j = 0; j < sz - 1; ++j)
            temp.push_back(result[i - 1][j] + result[i - 1][j + 1]);

        temp.push_back(1);

        result.push_back(temp);
        sz++;
    }
    return result;
}

// https://leetcode.com/explore/learn/card/recursion-i/251/scenario-i-recurrence-relation/3234/

std::vector<int> getRow(int rowIndex) {
    int sz = 1;
    std::vector<int> temp = {1};
    std::vector<int> result(temp);
    for (int i = 0; i < rowIndex; ++i) {
        temp.clear();

        temp.push_back(1);

        for (int j = 0; j < sz - 1; ++j)
            temp.push_back(result[j] + result[j + 1]);

        temp.push_back(1);

        result = temp;
        sz++;
    }
    return result;        
}