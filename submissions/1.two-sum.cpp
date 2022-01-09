/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
#include <vector> 
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> data;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            if (data.count(num)) {
                data[num].push_back(i);
            }
            else {
                data[num] = {i};
            }
        }
        for (auto iter = data.begin(); iter != data.end(); ++iter) {
            int tmp = target - iter->first;
            if (data.count(tmp))
            {
                if (tmp == iter->first) {
                    if (iter->second.size() > 1)
                    return iter->second;
                }
                else 
                    return {iter->second[0], data[tmp][0]};
            }
        }
        return {};
    }
};
// @lc code=end

