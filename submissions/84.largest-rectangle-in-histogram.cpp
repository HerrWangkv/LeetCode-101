/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ret = 0;
        stack<int> stk;
        vector<int> left(n, -1); //记录左侧最近的小于当前元素的元素的索引。没有则输出 -1
        vector<int> right(n, n); //记录右侧最近的小于等于当前元素的元素的索引。没有则输出 size
        /*
        for (int i = 0; i < n; ++i) {
            // 单调递增栈，相等元素记录较大的索引
            while (!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            // 单调递增栈，相等元素记录较小的索引
            while (!stk.empty() && heights[i] <= heights[stk.top()])
                stk.pop();
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        */
        for (int i = 0; i < n; ++i) {
            // 单调递增栈，相等元素记录较大的索引
            while (!stk.empty() && heights[i] <= heights[stk.top()]) {
                right[stk.top()] = i;
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; ++i) {
            cout << left[i] << right[i] << endl;
            ret = max(ret, heights[i] * (right[i] - left[i] - 1));
        }
        return ret;
    }
};
// @lc code=end

