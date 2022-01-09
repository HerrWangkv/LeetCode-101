/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int maxArea(vector<int>& height) {
        int ret = 0, n = height.size();
        int l = 0, r = n - 1, h = 0;
        while (l < r) {
            h = min(height[l], height[r]);
            ret = max(ret, (r - l) * h);
            while (l < r && height[l] <= h)
                ++l;
            while (l < r && height[r] <= h)
                --r;
        }
        return ret;
    }
};
// @lc code=end

