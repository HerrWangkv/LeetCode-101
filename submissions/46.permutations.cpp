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
    void backtracking(vector<int> &num, int pos) {
        if (pos == num.size()) {
            ret.push_back(num);
            return;
        }   
        for (int i = pos; i < num.size(); ++i) {
            // 假设pos-1已经定下来的情况下，则pos处需要考虑剩下的所有数字(包括原pos处的)的可能性
            swap(num[pos], num[i]);
            backtracking(num, pos + 1);
            swap(num[pos], num[i]);
        }
    }
    vector<vector<int>> permute(vector<int> &nums)
    {        
        backtracking(nums, 0);
        return ret;
    }
};
// @lc code=end

