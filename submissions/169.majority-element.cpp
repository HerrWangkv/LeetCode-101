/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> counter;
        for (int i = 0; i < n; ++i)
        {
            ++counter[nums[i]];
        }
        for (auto iter = counter.begin(); iter != counter.end(); ++iter) {
            if (iter->second > n / 2)
                return iter->first;
        }
        return 0;
    }
};
// @lc code=end

