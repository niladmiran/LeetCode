//
// Created by jacob on 2021/3/26.
//

#include <cstdint>

uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    int curBit;
    for (int i = 0; i < 32; ++i) {
        curBit = (n & 1);
        if (curBit) ans = ans * 2 + curBit;
        else ans = ans << 1;
        n = (n >> 1);
    }
    return ans;
}