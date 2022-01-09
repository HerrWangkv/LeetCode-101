/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(nums[i]);
        }
        int ret = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!s.count(nums[i] - 1)) {
                int current = 1;
                while (s.count(nums[i] + current)) {
                    ++current;
                }
                ret = max(ret, current);
            }
        }
        return ret;
    }
};
// @lc code=end

