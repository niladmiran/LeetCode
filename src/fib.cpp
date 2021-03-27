//
// Created by jacob on 2021/3/27.
//
#include <map>

// https://leetcode.com/explore/learn/card/recursion-i/255/recursion-memoization/1661/

std::map<int, int> dic = {{0, 0}, {1, 1}};
int fib(int n) {
    if (dic.find(n) != dic.end())   return dic[n];
    dic[n] = fib(n - 1) + fib(n - 2);

    return dic[n];
}