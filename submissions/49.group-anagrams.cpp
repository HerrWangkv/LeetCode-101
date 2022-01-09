/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> data;
        for (int i = 0; i < strs.size(); ++i) {
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            if (data.count(copy))
                data[copy].push_back(strs[i]);
            else
                data[copy] = {strs[i]};
        }
        vector<vector<string>> ret;
        for (auto iter = data.begin(); iter != data.end(); ++iter) {
            ret.push_back(iter->second);
        }
        return ret;
    }
};
// @lc code=end

