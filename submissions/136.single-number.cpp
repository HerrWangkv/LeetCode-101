/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ret ^= nums[i];
        }
        return ret;
    }
};
// @lc code=end

