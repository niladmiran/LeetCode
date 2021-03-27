//
// Created by jacob on 2021/3/27.
//
#include <string>
#include <bits/stdc++.h>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/884/


int myAtoi(std::string s) {
    int sz = s.size();
    int i = 0;
    int sign = 1;
    // skip the leading space
    while (i < sz && s[i] == ' ')   
        i++;
    if (i == sz)    return 0;
    if (s[i] == '-'){
        sign = -1;
        i++;
    }else if (s[i] == '+'){
        i++;
    }else if (s[i] > '9' && s[i] < '0')
        return 0;
    
    int ans = 0;
    while (i < sz && s[i] <= '9' && s[i] >= '0'){
        if (ans > 214748364)
            return sign > 0 ? INT_MAX : INT_MIN;
        if (ans == 214748364){
            if (sign > 0 && s[i] - '0' > 6)
                return INT_MAX;
            if (sign < 0 && s[i] - '0' > 7)
                return INT_MIN;
        }
        ans = ans * 10 + (s[i] - '0');
        i++;
    }
    return sign * ans;
}