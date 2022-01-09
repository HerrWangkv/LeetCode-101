/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        unordered_set<string> dict;
        for (int i = 0; i < wordDict.size(); ++i) {
            dict.insert(wordDict[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                string str = s.substr(j, i - j);
                dp[i] = dp[j] && dict.count(str);
                if (dp[i])
                    break;
            }
            //cout << i << dp[i] << endl;
        }
        return dp[n];
    }
};
// @lc code=end

