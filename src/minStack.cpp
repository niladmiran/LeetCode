//
// Created by jacob on 2021/3/26.
//

#include <stack>

// https://leetcode.com/explore/interview/card/top-interview-questions-easy/98/design/562/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}

    void push(int val) {
        data.push(val);
        if (minElement.empty() || val <= minElement.top())
            minElement.push(val);
    }

    void pop() {
        if (data.top() == minElement.top())
            minElement.pop();
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minElement.top();
    }

private:
    std::stack<int> data;
    std::stack<int> minElement;
};