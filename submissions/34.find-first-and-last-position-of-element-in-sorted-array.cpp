/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ret{-1, -1};
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || (mid > 0 && nums[mid - 1] != target)) {
                    ret[0] = mid;
                    break;
                }
                else
                    right = mid - 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (ret[0] == -1)
            return ret;
        left = 0;
        right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                if (mid == n - 1 || (mid < n - 1 && nums[mid + 1] != target)) {
                    ret[1] = mid;
                    break;
                }
                else
                    left = mid + 1;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ret;
    }
};
// @lc code=end

