//
// Created by jacob on 2021/3/28.
//

// https://leetcode.com/explore/learn/card/recursion-i/256/complexity-analysis/2380/


double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n == -1)    return 1.0 / x;
    double temp = myPow(x, n / 2);
    temp *= temp;
    if (n < 0)  x = 1.0 / x;
    if (n % 2)  return x * temp;
    else    return temp;
}