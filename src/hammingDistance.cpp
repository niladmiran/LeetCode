//
// Created by jacob on 2021/3/26.
//

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/99/others/762/

int hammingDistance(int x, int y) {
    int count = 0;
    int num = 1;
    for (int i = 0; i < 32; ++i){
        num = 1 << i;
        if ((x & num) != (y & num))
            count++;
    }
    return count;
}