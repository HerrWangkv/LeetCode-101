/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> data{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        return combine(digits, 0, data);
    }
    vector<string> combine(string &digits, int start, vector<string> &data) {
        vector<string> ret;
        if (start == digits.size()) {
            return {""};
        }
        else {
            for (auto ch : data[digits[start] - '2']) {
                for (auto str : combine(digits, start + 1, data)) {
                    ret.push_back(string(1, ch) + str);
                }
            }
            return ret;
        }
    
    }
};
// @lc code=end

