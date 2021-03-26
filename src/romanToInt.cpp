//
// Created by jacob on 2021/3/26.
//
#include <map>
#include <string>

int romanToInt(std::string s) {
    std::map<char, int> dic = {{'I',1}, {'V',5}, {'X',10},
                               {'L',50}, {'C',100}, {'D',500},
                               {'M',1000}};
    int ans = 0;
    int sz = s.size();
    for (int i = 1; i < sz; ++i){
        if (dic[s[i]] > dic[s[i-1]])    ans -= dic[s[i - 1]];
        else    ans += dic[s[i - 1]];
    }
    ans += dic[s[sz - 1]];
    return ans;
}