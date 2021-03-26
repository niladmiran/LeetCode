//
// Created by jacob on 2021/3/26.
//
#include <string>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/

bool isAlphaNumeric(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

char toLower(char c) {
    if (c >= 'A' && c <= 'Z') c += 32;
    return c;
}

bool isPalindrome(std::string s) {
    auto right = s.size() - 1;
    auto left = 0;
    while (left < right) {
        while (!isAlphaNumeric(s[left]) && left < right) left++;
        while (!isAlphaNumeric(s[right]) && left < right) right--;
        if (toLower(s[left]) == toLower(s[right])) {
            left++;
            right--;
        } else return false;
    }
    return true;
}