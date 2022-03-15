/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        //dp[i][j]表示逐渐填满i和j之间的所有气球(不包括i和j)最多能获得多少金币          
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2);
        val[0] = val[n + 1] = 1;
        for (int i = 1; i <= n; ++i) {
            val[i] = nums[i - 1];
        }
        // 需要先求
        for (int i = n + 1; i >= 0; --i){
            for (int j = i + 2; j < n + 2; ++j) {
                // 假设 k 是开区间(i,j)中最后一个被扎破的气球
                for (int k = i + 1; k < j; ++k) {
                    int coin = val[i] * val[k] * val[j];
                    dp[i][j] = max(dp[i][j], dp[i][k] + coin + dp[k][j]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
// @lc code=end

