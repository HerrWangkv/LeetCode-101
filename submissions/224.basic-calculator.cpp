/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    // The index of which we are looking at
    int i;
    int helper(string &s) {
        // only ints are saved in this stack, either positive or negative
        stack<int> stk;
        int n = s.size();
        char op;
        // possible negative numbers at first or right after `(`
        if (s[i] == '-')
            op = '-';
        else
            op = '+';
        while (i < n)
        {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num *= 10;
                    num += s[i] - '0';
                    ++i;
                }
                if (op == '+')
                    stk.push(num);
                else if (op == '-')
                    stk.push(-1 * num);
                /* 
                // if `*` is also considered
                else if (op == '*') {
                    int tmp = stk.top();
                    stk.pop();
                    tmp *= num;
                    stk.push(tmp);
                }
                */
            }
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                op = s[i];
                ++i;
            }
            // recursivly call `helper` if there is a `(`. Note the `i` keeps moving
            else if (s[i] == '(') {
                ++i;
                int num = helper(s);
                if (op == '+')
                    stk.push(num);
                else if (op == '-')
                    stk.push(-1 * num);
                /* 
                // if `*` is also considered
                else if (op == '*') {
                    int tmp = stk.top();
                    stk.pop();
                    tmp *= num;
                    stk.push(tmp);
                }
                */
            }
            else if (s[i] == ')') {
                ++i;
                break;
            }
            else if (s[i] == ' ')
                ++i;
        }
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
    int calculate(string s) {
        i = 0;
        return helper(s);
    }
};
// @lc code=end

