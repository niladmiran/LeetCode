//
// Created by jacob on 2021/3/26.
//

#include <stack>
#include <string>

bool isValid(std::string s) {
    std::stack<char> result;
    std::string temp = "([{";
    for (std::string::iterator it = s.begin(); it != s.end(); ++it){
        if (temp.find(*it) != std::string::npos)
            result.push(*it);
        else{
            if (result.empty()) return false;
            char c = result.top();
            if ((*it == '}' && c == '{') ||
                (*it == ')' && c == '(') ||
                (*it == ']' && c == '['))
                result.pop();
            else
                return false;
        }
    }
    if (result.empty()) return true;
    return false;
}