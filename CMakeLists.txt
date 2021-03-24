cmake_minimum_required(VERSION 3.17)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeetCode main.cpp src/Solution.cpp include/Solution.h src/My_sort.cpp src/TreeNode.cpp include/TreeNode.h src/ListNode.cpp include/ListNode.h src/Useful_function.cpp src/climbStairs.cpp src/maxProfit.cpp src/maximumSubarray.cpp src/rob.cpp src/removeDuplicates.cpp src/maxProfitII.cpp)