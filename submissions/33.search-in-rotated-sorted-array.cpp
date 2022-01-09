/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int k = 0, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i - 1]) {
                k = i;
                break;
            }
        }
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[(mid + k) % n] == target)
                return (mid + k) % n;
            else if (nums[(mid + k) % n] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
// @lc code=end

