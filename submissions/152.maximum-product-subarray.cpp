/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), ret = nums[0];
        int min_val = ret, max_val = ret;
        for (int i = 1; i < n; ++i) {
            int tmp1 = min_val * nums[i], tmp2 = max_val * nums[i];
            if (tmp1 > tmp2) {
                max_val = max(nums[i], tmp1);
                min_val = min(nums[i], tmp2);
            }
            else {
                max_val = max(nums[i], tmp2);
                min_val = min(nums[i], tmp1);
            }
            ret = max(ret, max_val);
        }
        return ret;
    }
};
// @lc code=end

