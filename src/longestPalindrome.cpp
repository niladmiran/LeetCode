//
// Created by jacob on 2021/4/6.
//
#include <string>
#include <vector>

// https://leetcode.com/problems/longest-palindromic-substring/submissions/



std::string longestPalindrome(std::string s) {
    int best_left = 0, best_right = 0;
    for (int i = 0; i < s.size(); ++i) {
        int left = i, right = i;
        while (right + 1 < s.size() && s[right + 1] == s[i])
            right++;
        while (left - 1 > 0 && s[left - 1] == s[i])
            left--;
        while (left > 0 && right < s.size() - 1 && s[left - 1] == s[right + 1]) {
            left--;
            right++;
        }
        if (right - left > best_right - best_left) {
            best_left = left;
            best_right = right;
        }
    }
    return s.substr(best_left, best_right - best_left + 1);
}

std::string longestPalindrome(std::string s, int p) {
    std::vector<std::vector<bool>> table(s.size(), std::vector<bool>(s.size(), false));
    int maxLength = 1;
    int bestStart = 0;
    // length of 1
    for (int i = 0; i < s.size(); ++i) table[i][i] = true;
    // length of 2
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == s[i + 1]) {
            table[i][i + 1] = true;
            if (maxLength == 1) {
                maxLength = 2;
                bestStart = i;
            }
        }
    }
    // length greater than or equal to 3
    for (int i = 3; i <= s.size(); ++i) {
        // start index
        for (int j = 0; j < s.size() - i + 1; ++j) {
            // end index
            int k = i + j - 1;

            // decide whether to update the best one
            if (table[j + 1][k - 1] && s[j] == s[k]) {
                table[j][k] = true;
                if (i > maxLength) {
                    maxLength = i;
                    bestStart = j;
                }
            }
        }
    }
    return s.substr(bestStart, maxLength);
}