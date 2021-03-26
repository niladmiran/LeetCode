//
// Created by jacob on 2021/3/26.
//

#include <cstdint>

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n){
        n &= (n - 1);
        count++;
    }
    return count;
}
