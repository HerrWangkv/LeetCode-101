/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, 1);
        for (int i = 1; i < n; ++i) {
            ret[i] = ret[i - 1] * nums[i - 1];
        }
        int tmp = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            tmp *= nums[i + 1];
            ret[i] *= tmp;
        }
        return ret;
    }
};
// @lc code=end

