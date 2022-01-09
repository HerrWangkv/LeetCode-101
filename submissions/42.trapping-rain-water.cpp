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
        int n = height.size();
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0, ret = 0;
        while (left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            if (height[left] < height[right]) {
                //也表明leftMax < rightMax
                ret += leftMax - height[left];
                ++left;
            }
            else {
                ret += rightMax - height[right];
                --right;
            }
        }
        return ret;
    }
};
// @lc code=end

