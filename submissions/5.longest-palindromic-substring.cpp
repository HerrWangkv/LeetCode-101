/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2)
            return s;
        // dp[i][j]: whether s[i:j] is a palindrome
        // dp[i][j] = s[i] == s[j] & (i + 1 == j | dp[i+1][j-1])
        // j >= i
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string ret = "";
        ret += s[0];
        for (int i = 0; i < n; ++i)
            dp[i][i] = true;
        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && (dp[i + 1][j - 1] || (i + 1 == j));
                //cout << i << j << dp[i][j] << endl;
                if (dp[i][j] && j - i + 1 > ret.size())
                {
                    ret = s.substr(i, j - i + 1);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

