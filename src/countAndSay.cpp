//
// Created by jacob on 2021/3/27.
//
#include <string>


std::string countAndSay(int n) {
    if (n == 1) return "1";
    if (n == 2) return "11";

    std::string s = "11";
    for (int i = 3; i <= n; ++i) {
        s.push_back('$');
        int sz = s.size();
        int count = 1;
        std::string s_new;
        for (int j = 1; j < sz; ++j) {
            if (s[j] == s[j - 1]) count++;
            else {
                s_new.push_back('0' + count);
                s_new.push_back(s[j - 1]);
                count = 1;
            }
        }
        s = s_new;
    }
    return s;
}