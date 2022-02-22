/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        while (right < n) {
            if (nums[left] == 0) {
                while (right < n && nums[right] == 0) 
                    ++right;
            }
            if (right == n)
                break;
            swap(nums[left], nums[right]);
            ++left;
            ++right;
        }
        for (int i = left; i < n; ++i)
            nums[i] = 0;
    }
};
// @lc code=end

