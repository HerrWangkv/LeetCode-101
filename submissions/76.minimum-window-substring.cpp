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
        string ret;
        int m = s.size(), n = t.size();
        if (m < n)
            return ret;
        unordered_map<char, int> goal;
        unordered_map<char, int> window;
        int counter = 0; // determine whether this window contains all needed letters
        int minLength = INT_MAX;
        for (auto ch : t)
            ++goal[ch];
        int left = 0, right = 0;
        while (right < m) {
            while (right < m && counter < n) {
                if (goal.count(s[right])) {
                    ++window[s[right]];
                    if (window[s[right]] <= goal[s[right]])
                        ++counter;
                }
                ++right;
            }
            //cout << right << " ";
            while (left <= right - n)
            {
                if (!goal.count(s[left]) || (window[s[left]] > goal[s[left]]))
                {
                    --window[s[left]];
                    ++left;
                }
                else {
                    break;
                }
            }
            //cout << left << endl;
            if (counter == n && (right - left) < minLength) {
                minLength = (right - left);
                //cout << minLength << endl;
                ret = s.substr(left, minLength);
            }
            --window[s[left]];
            ++left;
            --counter;
        }
        return ret;
    }
};
// @lc code=end

