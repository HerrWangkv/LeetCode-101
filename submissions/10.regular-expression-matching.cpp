/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        /*
        // true if s[0,i) matches p[0,j)
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j) {
                // j >= 2
                if (p[j-1] == '*')
                    // dp[i][j-2]: p[j-2] should be repeated 0 times
                    // dp[i-1][j]: p[j-2] can be repeated multiple times
                    // 注意必须是dp[i-1][j] 而不是dp[i-1][j-1]
                    dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i-1] == p[j - 2] || p[j - 2] == '.'));
                else
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
        return dp[m][n];
        */
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i <= m; ++i)
        {
            bool pre = dp[0];
            dp[0] = !i;
            for (int j = 1; j <= n; ++j)
            {
                bool tmp = dp[j];
                if (p[j - 1] == '*')
                    dp[j] = dp[j - 2] || (i && dp[j] && (s[i-1] == p[j - 2] || p[j - 2] == '.'));
                else
                    dp[j] = i && pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                pre = tmp;
            }
        }
        return dp[n];
    }
};
// @lc code=end

