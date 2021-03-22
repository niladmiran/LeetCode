
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "include/Solution.h"
#include "include/ListNode.h"

#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 4, index = 0, maxSum = 4;
    int maxN = sol.maxValue(n, index, maxSum);
    cout << maxN << endl;
    return 0;
}
