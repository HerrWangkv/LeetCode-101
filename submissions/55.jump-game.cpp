/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_pos = nums[0], right = 0;
        while (right < n && right <= max_pos) {
            int pos = right + nums[right];
            if (pos >= n - 1)
                return true;
            max_pos = max(max_pos, pos);
            ++right;
        }
        return false;
    }
};
// @lc code=end

