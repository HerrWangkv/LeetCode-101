/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp(n, 0);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0)
                    dp[j] = grid[0][j];
                else if (i == 0)
                    dp[j] = dp[j - 1] + grid[i][j];
                else if (j == 0)
                    dp[j] = dp[j] + grid[i][j];
                else 
                    dp[j] = (dp[j] < dp[j - 1] ? dp[j] : dp[j - 1]) + grid[i][j];
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

