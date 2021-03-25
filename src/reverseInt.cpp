//
// Created by jacob on 2021/3/25.
//
#include <bits/stdc++.h>

int abs(int a){
    return a >= 0 ? a : -a;
}

int reverse(int x){
    int maxNum = INT_MAX / 10;
    int ans = 0;
    while (x){
        if (abs(ans) > maxNum)   return 0;
        ans = ans * 10 + (x % 10);
        x /= 10;
    }
    return ans;
}