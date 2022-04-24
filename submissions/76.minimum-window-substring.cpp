// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem76.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include <iostream>
#include <string>
#include <unordered_map> 
#include <limits.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> goal, win;
        int count = 0;
        for (auto ch : t) {
            ++goal[ch];
            ++count;
        }
        int len = s.size();
        string ret = "";
        int i = 0, j = 0;
        while (j < s.length()) {
            while (j < s.length() && count) {
                if (goal.count(s[j])) {
                    if (goal[s[j]] > win[s[j]])
                        --count;
                    ++win[s[j]];
                }
                ++j;
            }
            while (!count) {
                if (goal.count(s[i])) {
                    if (win[s[i]] == goal[s[i]])
                        ++count;
                    --win[s[i]];
                }
                ++i;
            }
            if (j - i + 1 <= len) {
                ret = s.substr(i - 1, j - i + 1);
                len = j - i + 1;
            }
        }
        return ret;
    }
};
// @lc code=end

