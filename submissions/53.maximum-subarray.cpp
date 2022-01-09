/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ret = nums[0];
        vector<int> dp(nums.begin(), nums.end());
        for (int i = 1; i < n; ++i) {
            dp[i] = (dp[i - 1] > 0 ? dp[i - 1] : 0) + dp[i];
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
// @lc code=end

