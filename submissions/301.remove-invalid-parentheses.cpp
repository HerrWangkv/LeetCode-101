/*
 * @lc app=leetcode id=301 lang=cpp
 *
 * [301] Remove Invalid Parentheses
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool isValid(string s) {
        int count = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                ++count;
            else if (s[i] == ')')
                --count;
            if (count < 0)
                return false;
        }
        return count == 0;
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> currentSet;
        currentSet.insert(s);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            for (auto iter = currentSet.begin(); iter != currentSet.end(); ++iter) {
                if (isValid(*iter)) {
                    res.push_back(*iter);
                }
            }
            if (!res.empty())
                return res;
            unordered_set<string> nextSet;
            for (auto &str : currentSet) {
                for (int j = 0; j < str.size(); ++j) {
                    // 避免重复
                    if (j > 0 && str[j] == str[j-1])
                        continue;
                    if (str[j] == '(' || str[j] == ')')
                        nextSet.insert(str.substr(0, j) + str.substr(j + 1));
                }
            }
            currentSet = nextSet;
        }
        return {""};
    }
};
// @lc code=end

