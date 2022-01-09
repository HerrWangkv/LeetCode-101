/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), ret = 0;
        // length ending at i
        vector<int> dp(n, 0);
        for (int i = 1; i < n; ++i)
        {
            if (s[i] == ')') {
                if (s[i-1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] + 2: 2);
                else if (i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '(')
                    dp[i] = dp[i - 1] + 2 + (i - dp[i-1] - 2 >= 0 ? dp[i - dp[i-1] - 2] : 0);
            }
            ret = max(ret, dp[i]);
        }
            return ret;
    }
};
// @lc code=end

