/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start

#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    bool isValid(string s) {
        int n = s.size();
        if (n & 1)
            return false;
        stack<char> stk;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
                stk.push(s[i]);
            else {
                if (stk.empty())
                    return false;
                if (s[i] == '}' && stk.top() != '{')
                    return false;
                else if (s[i] == ']' && stk.top() != '[')
                    return false;
                else if (s[i] == ')' && stk.top() != '(')
                    return false;
                else
                    stk.pop();
            }
        }
        return stk.empty();
    }
};
// @lc code=end

