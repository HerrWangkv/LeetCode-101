/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
#include <stack>
using namespace std;
class MinStack
{
public:
    stack<int> stk;
    stack<int> mins;
    MinStack() {

    }

    void push(int val) {
        stk.push(val);
        if (!mins.empty())
            mins.push(min(val, mins.top()));
        else
            mins.push(val);
    }

    void pop() {
        stk.pop();
        mins.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

