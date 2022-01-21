/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0)
                dp[i] = max(dp[i], dp[i - 1]);
            if (i > 1)
                dp[i] = max(dp[i], dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};
// @lc code=end

