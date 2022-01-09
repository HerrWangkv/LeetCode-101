/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ret;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
            { return (a[0] < b[0]); });
        for (int i = 0; i < n; ++i)
        {
            if (ret.empty() || intervals[i][0] > ret.back()[1])
                ret.push_back(intervals[i]);
            else {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            }
        }
        return ret;
    }
};
// @lc code=end

