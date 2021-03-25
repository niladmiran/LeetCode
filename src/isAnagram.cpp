//
// Created by jacob on 2021/3/25.
//
#include <string>
#include <map>

bool isAnagram(std::string s, std::string t) {
    std::map<char, int> ans;
    int szs = s.size(), szt = t.size();
    if (szs != szt) return false;
    for (int i = 0; i < szs; ++i){
        ans[s[i]]++;
        ans[t[i]]--;
    }
    for (int i = 0; i < szs; ++i){
        if (ans[s[i]] != 0) return false;
    }
    return true;
}