//
// Created by jacob on 2021/4/7.
//

bool isPalindrome(int x) {
    if (x < 0) return false;
    int MAX_NUM = 214748364;
    int ans = 0;
    int temp = x;
    while (temp) {
        if (ans >= MAX_NUM) return false;
        ans = ans * 10 + (temp % 10);
        temp /= 10;
    }
    if (ans == x) return true;
    return false;
}