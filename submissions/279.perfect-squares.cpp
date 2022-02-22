/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    int numSquares(int n) {
        int ret = 0;
        queue<int> q;
        q.push(n);
        while (!q.empty()) {
            int num = q.size();
            ++ret;
            for (int i = 0; i < num; ++i)
            {
                int rest = q.front();
                q.pop();
                for (int j = 1; j * j <= rest; ++j)
                {
                    if (j * j == rest)
                        return ret;
                    q.push(rest - j * j);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

