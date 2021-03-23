//
// Created by jacob on 2021/3/23.
//
#include <vector>
#include <bits/stdc++.h>

int maxSubArray(std::vector<int>& nums) {
    int sz = nums.size();
    if (sz == 1)    return nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < sz; ++i){
        nums[i] = std::max(nums[i] + nums[i-1], nums[i]);
        maxSum = std::max(maxSum, nums[i]);
    }

    return maxSum;
}

// use divide and conquer method
int maxThreeNums(int a, int b, int c){
    return std::max(std::max(a, b), c);
}

int maxCrossMidSubArray(std::vector<int>& nums, int left, int mid, int right){
    // maximum sum on the right that contains the mid (included)
    int sum = 0;
    int leftSum = INT_MIN;
    for (int i = mid; i >= left; --i) {
        sum += nums[i];
        if (sum >= leftSum)   leftSum = sum;
    }
    // maximum sum on the right that contains the mid (excluded)
    sum = 0;
    int rightSum = INT_MIN;
    for (int i = mid + 1; i <= right; ++i) {
        sum += nums[i];
        if (sum >= rightSum)  rightSum = sum;
    }
    return maxThreeNums(leftSum, leftSum + rightSum, rightSum);
}

int maxSubArray(std::vector<int>& nums, int left, int right){
    if (left == right)  return nums[left];
    int mid = left + (right - left) / 2;
    return maxThreeNums(maxSubArray(nums, left, mid),
                        maxSubArray(nums, mid + 1, right),
                        maxCrossMidSubArray(nums, left, mid, right));
}

int maxSubArray(std::vector<int>& nums, int dummyNum) {
    int sz = nums.size();
    int left = 0, right = sz - 1;
    int maxSum = maxSubArray(nums, left, right);
    return maxSum;
}



