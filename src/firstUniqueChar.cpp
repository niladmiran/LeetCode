//
// Created by jacob on 2021/3/27.
//

#include <string>
#include <map>

int firstUniqChar(std::string s) {
    std::map<char, int> record;
    int sz = s.size();
    for (int i = 0; i < sz; ++i)
        record[s[i]]++;
    for (int i = 0; i < sz; ++i)
        if (record[s[i]] == 1) return i;
    return -1;
}