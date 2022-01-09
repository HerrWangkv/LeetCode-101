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
        // 该元素所在列以该元素结尾的‘1’串的长度，可以理解为84题中的柱状图高度
        vector<vector<int>> up(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(matrix[i][j] == '1')
                    up[i][j] = (i == 0 ? 0 : up[i - 1][j]) + 1;
            }
        }
        // 需要将整个表每行当作一个柱状图进行理解
        for (int i = 0; i < m; ++i) {
            // 下面就是84题
            stack<int> stk;
            vector<int> left(n, -1), right(n, n);
            for (int j = 0; j < n; ++j) {
                while (!stk.empty() && up[i][stk.top()] >= up[i][j]) {
                    right[stk.top()] = j;
                    stk.pop();
                }
                left[j] = stk.empty() ? -1 : stk.top();
                stk.push(j);
            }
            for (int j = 0; j < n; ++j) {
                int len = right[j] - left[j] - 1;
                int area = up[i][j] * len;
                ret = max(ret, area);
            }
        }
        return ret;
    }
};
// @lc code=end

