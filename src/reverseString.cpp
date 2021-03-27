//
// Created by jacob on 2021/3/25.
//
#include <vector>
#include <string>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/879/

void reverseString(std::vector<char>& s) {
    int sz = s.size();
    int left = 0, right = sz - 1;
    while (left < right){
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

void reverseString(std::vector<char>& s, int k) {
    if (s.size() == 1)  return;
    char temp = s[0];
    s.erase(s.begin());
    reverseString(s, k);
    s.push_back(temp);
}
