/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
private:
    vector<vector<int>> ret;
public:
    void helper(vector<int>& nums, vector<int> &current, int left) {
        ret.push_back(current);
        if (left >= nums.size())
            return;
        for (int i = left; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            helper(nums, current, i + 1);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> start{};
        helper(nums, start, 0);
        return this->ret;
    }
};
// @lc code=end

