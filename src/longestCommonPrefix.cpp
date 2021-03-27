//
// Created by jacob on 2021/3/27.
//
#include <string>
#include <vector>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/887/


std::string longestCommonPrefix(std::vector<std::string> &strs) {
    if (strs.empty()) return "";
    std::string s;
    int sz = strs.size();
    int len = strs[0].size();
    for (int i = 0; i < sz; ++i) {
        if (strs[i].size() < len) len = strs[i].size();
    }
    for (int i = 0; i < len; ++i) {
        char c = strs[0][i];
        for (int j = 0; j < sz; ++j) {
            if (strs[j][i] != c) return s;
        }
        s.push_back(c);
    }
    return s;
}