/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ret;
    int n;

    void helper(vector<int> &nums, int pos, vector<int> &current)
    {
        if (pos == n) {
            ret.push_back(current);
            return;
        }
        for (int i = 0; i <= current.size(); ++i) {
            // gradually insert new digit into the permutation
            current.insert(current.begin() + i, nums[pos]);
            helper(nums, pos + 1, current);
            current.erase(current.begin() + i);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();
        vector<int> vec{};
        helper(nums, 0, vec);
        return ret;
    }
};
// @lc code=end

