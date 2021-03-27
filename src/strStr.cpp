//
// Created by jacob on 2021/3/27.
//
#include <string>
#include <bits/stdc++.h>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/885/


int strStr(std::string haystack, std::string needle) {
    if (needle.empty()) return 0;
    if (haystack.empty()) return -1;
    int n = haystack.size(), m = needle.size();
    if (n < m)  return -1;
    
    int i;
    for (i = 0; i <= n - m; ++i){
        int k = i;
        int j;
        for (j = 0; j < m; ++j){
            if (needle[j] != haystack[k])   break;
            k++;
        }
        if (j == m) return i;
    }
    return -1;
}