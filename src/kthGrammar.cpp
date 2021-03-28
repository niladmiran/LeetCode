//
// Created by jacob on 2021/3/27.
//

// https://leetcode.com/explore/learn/card/recursion-i/253/conclusion/1675/


int kthGrammar(int N, int K) {
    if (N == 1) return 0;
    if (K == 1) return 0;
    if (K % 2 == 0) return 1 - kthGrammar(N - 1, K / 2);
    return kthGrammar(N - 1, (K + 1) / 2);
}