//
// Created by jacob on 2021/3/24.
//
#include <vector>
#include <algorithm> 

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/559/

std::vector<int> plusOne(std::vector<int>& digits) {
    int operand = 1;
    int sz = digits.size();
    std::reverse(digits.begin(), digits.end());
    int carry = operand;
    for (int i = 0; i < sz; ++i){
        if (digits[i] + carry >= 10){
            digits[i]  = digits[i] + carry;
            carry = digits[i] / 10;
            digits[i] %= 10;

        }else{
            digits[i] += carry;
            carry = 0;   
        }
        
        if (!carry) break; 
    }
    if (carry) digits.push_back(carry);
    
    std::reverse(digits.begin(), digits.end());
    return digits;
}