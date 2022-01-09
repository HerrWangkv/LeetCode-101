/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution
{
public:
    vector<vector<int>> ret;
    void helper(vector<int> &candidates, int i, vector<int> &current, int target) {
        if (target == 0)
        {
            ret.push_back(current);
            return;
        }
        if (i + 1 < candidates.size() && candidates[i+1] <= target)
            helper(candidates, i + 1, current, target);
        if (candidates[i] <= target) {
            current.push_back(candidates[i]);
            helper(candidates, i, current, target - candidates[i]);
            current.pop_back();
        }
    }
        vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> vec{};
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, vec, target);
        return this->ret;
    }
};
// @lc code=end

