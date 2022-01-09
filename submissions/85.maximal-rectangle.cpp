/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;
class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ret = 0;
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0)
            return ret;
        vector<int> up(n, 0);
        // 需要将整个表每行当作一个柱状图进行理解
        for (int i = 0; i < m; ++i) {
            // 下面就是84题
            stack<int> stk;
            vector<int> left(n, -1), right(n, n);
            for (int j = 0; j < n; ++j) {
                // 该元素所在列以该元素结尾的‘1’串的长度，可以理解为84题中的柱状图高度
                if (i == 0)
                    up[j] = (matrix[i][j] == '1');
                else {
                    if (matrix[i][j] == '1')
                        ++up[j];
                    else
                        up[j] = 0;
                }
                while (!stk.empty() && up[j] <= up[stk.top()]) {
                    right[stk.top()] = j;
                    stk.pop();
                }
                if (!stk.empty()) {
                    left[j] = stk.top();
                }
                stk.push(j);
            }
            for (int j = 0; j < n; ++j) {
                ret = max(ret, (right[j] - left[j] - 1) * up[j]);
            }
        }
        return ret;
    }
};
// @lc code=end

