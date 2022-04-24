/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int ret = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                ++l;
                leftMax = height[l] > leftMax ? height[l] : leftMax;
                ret += leftMax - height[l];
            }
            else {
                --r;
                rightMax = height[r] > rightMax ? height[r] : rightMax;
                ret += rightMax - height[r];
            }
        }
        return ret;
    }
};
// @lc code=end

