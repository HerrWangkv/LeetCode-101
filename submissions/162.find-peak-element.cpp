/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            //找到第一个比右侧相邻元素大的元素索引
            if (mid == nums.size() - 1 || nums[mid] > nums[mid + 1]) 
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;        
    }
};
// @lc code=end

