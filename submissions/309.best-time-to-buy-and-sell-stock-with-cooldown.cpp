/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(3));
        dp[0][0] = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            //dp[i][0]指当天掌控股票的最大累积收益
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);//一直持有 或 当天买入
            // dp[i][1]指当天卖出的最大累计收益
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            // dp[i][2]指当天无股票，提前卖出的最大累计收益
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};
// @lc code=end

