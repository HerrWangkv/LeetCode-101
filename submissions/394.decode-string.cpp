/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
#include<string>
#include <stack>
#include <cctype>
using namespace std;
class Solution
{
public:
    string getDigit(string &s, size_t &index) {
        string ret = "";
        while (isdigit(s[index])) {
            ret += s[index];
            ++index;
        }
        return ret;
    }
    string getAlpha(string &s, size_t &index) {
        string ret = "";
        while (isalpha(s[index])) {
            ret += s[index];
            ++index;
        }
        return ret;
    }
    string decodeString(string s) {
        stack<string> strs;
        size_t i = 0;
        while (i < s.size()) {
            if (isdigit(s[i])){
                string str = getDigit(s, i);
                strs.push(str);
                cout << str << endl;
            }
            else if (isalpha(s[i])) {
                string str = getAlpha(s, i);
                cout << str << endl;
                if (isdigit(strs.top()[0])) {
                    strs.push(str);
                }
                else {
                    string tmp = strs.top();
                    tmp = tmp + str;
                    strs.pop();
                    strs.push(tmp);
                }
            }
            else if (s[i] == '[')
                ++i;
            else {
                ++i;
                string str = strs.top();
                strs.pop();
                if (isdigit(strs.top()[0])) {
                    string num = strs.top();
                    strs.pop();
                    string tmp = "";
                    for (int j = 0; j < stoi(num); ++j)
                        tmp += str;
                    strs.push(tmp);
                }
                else {
                    string tmp = strs.top();
                    strs.pop();
                    tmp = tmp + str;
                    strs.push(tmp);
                }
            }
        }
        string ret = "";
        while (!strs.empty()) {
            ret = strs.top() + ret;
            strs.pop();
        }
        return ret;
    }
};
// @lc code=end

