/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

// @lc code=start
class Solution {
public:
    string addStrings(string s, string t) {
        if (s == "")
            return t;
        if (t == "")
            return s;
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        int n1 = s.length(), n2 = t.length();
        int i = 0, carry = 0;
        string ret = "";
        for (; i < min(n1, n2); ++i) {
            int tmp = (s[i] - '0') + (t[i] - '0') + carry;
            ret += (tmp % 10 + '0');
            carry = tmp / 10;
        }
        while (i < n1) {
            int tmp = (s[i] - '0') + carry;
            ret += (tmp % 10 + '0');
            carry = tmp / 10;
            ++i;
        }
        while (i < n2) {
            int tmp = (t[i] - '0') + carry;
            ret += (tmp % 10 + '0');
            carry = tmp / 10;
            ++i;
        }
        if (carry) {
            ret += '1';
        }
        reverse(ret.begin(), ret.end());
        return ret;
        
    }
};
// @lc code=end

