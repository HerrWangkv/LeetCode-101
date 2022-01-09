/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret = {};
        int i = 0;
        while (i < n - 2)
        {
            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    int tmp1 = nums[j], tmp2 = nums[k];
                    while (j < k && nums[j] == tmp1)
                        ++j;
                    while (j < k && nums[k] == tmp2)
                        --k;
                }
                else if (nums[i] + nums[j] + nums[k] < 0) {
                    int tmp1 = nums[j];
                    while (j < k && nums[j] == tmp1)
                        ++j;
                }
                else {
                    int tmp2 = nums[k];
                    while (j < k && nums[k] == tmp2)
                        --k;
                }
            }
            int tmp = nums[i];
            while (i < n - 2 && nums[i] == tmp)
                ++i;
        }
        return ret;
    }
};
// @lc code=end

