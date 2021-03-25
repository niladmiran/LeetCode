//
// Created by jacob on 2021/3/25.
//

// https://leetcode.com/explore/featured/card/top-interview-questions-easy/102/math/745/


bool isPowerOfThree(int n) {
    return (n > 0) && (1162261467 % n == 0);
}