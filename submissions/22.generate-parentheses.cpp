/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> ret;
    void helper(int open, int close, int n, string current)
    {
        if(current.length() == n * 2)
        {
            ret.push_back(current);
            return;
        }
        if(open < n)  helper(open + 1, close, n, current + "(");
        if(close < open)  helper(open, close + 1, n, current + ")");
    }

    vector<string> generateParenthesis(int n) {
        helper(0, 0, n, "");
        return ret;
    }
};
// @lc code=end

