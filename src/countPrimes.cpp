//
// Created by jacob on 2021/3/25.
//

// https://leetcode.com/explore/featured/card/top-interview-questions-easy/102/math/744/


bool isPrime(int n){
    if (n <= 0 || n == 1)   return false;
    if (n == 2 || n == 3)   return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i < n + 1;){
        if (n % i == 0)     return false;
        i = i + 2;
    }
    return true;
}

int countPrimes(int n) {
    int count = 0;
    for (int i = 2; i < n; ++i){
        if (isPrime(i)) count++;
    }
    return count;
}