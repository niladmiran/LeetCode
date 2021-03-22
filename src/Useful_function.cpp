//
// Created by jacob on 2021/3/15.
//

#include <string>
#include <algorithm>

// sum of two large numbers
std::string sumOfTwoLargeNumbers(std::string & a, std::string & b){
    // make sure a is large than b
    if (a.size() < b.size())    std::swap(a, b);

    // reverse two strings
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());

    int sz_a = a.size(), sz_b = a.size();

    std::string result;
    int sum, carry = 0;

    // add b to a
    for (int i = 0; i < sz_b; ++i) {
        sum = (a[i] - '0') + (b[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // add the remaining parts of a
    for (int i = sz_b; i < sz_a; ++i) {
        sum = (a[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // check if carry is zero
    if (carry)  result.push_back(carry + '0');

    // reverse the result
    std::reverse(result.begin(), result.end());

    return result;
}
