/*
 * @lc app=leetcode id=962 lang=cpp
 *
 * [962] Maximum Width Ramp
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> s;
        int res = 0;
        int n = nums.size();
        s.push(0);
        for (int i = 0; i < n; ++i)
        {
            if (s.empty() || nums[s.top()] > nums[i])
                s.push(i);
        }
        for (int j = n - 1; j >= 0; --j)
        {
            while (!s.empty() && nums[s.top()] <= nums[j])
            {
                res = max(res, j - s.top());
                s.pop();
            }
        }
        return res;

    }
};
// @lc code=end

