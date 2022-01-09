/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, left = 0, right = n - 1;
        while (i <= right) {
            if (nums[i] == 0) {
                swap(nums[left], nums[i]);//nums[left] can not be worse than nums[i]
                ++left;
                ++i;
            }
            else if (nums[i] == 2) {
                swap(nums[right], nums[i]);
                --right;
            }
            else
                ++i;
        }
    }
};
// @lc code=end

