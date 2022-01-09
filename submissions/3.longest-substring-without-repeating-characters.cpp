/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n < 2)
            return n;
        unordered_set<char> exist;
        int left = -1, right = 0, ret = 0;
        while (right < n) {
            while (exist.count(s[right])) {
                ++left;
                exist.erase(s[left]);
            }
            while (right < n && !exist.count(s[right])) {
                exist.insert(s[right]);
                ++right;
            }
            ret = max(ret, right - left - 1);
        }
        return ret;
    }
};
// @lc code=end

