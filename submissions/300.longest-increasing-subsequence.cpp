/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = 1, n = nums.size();
        if (!n)
            return n;
        // ret[i]保存长度为i的递增子序列的最小尾元素
        vector<int> ret(n + 1, 0);
        ret[len] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > ret[len])
                ret[++len] = nums[i];
            else {
                int left = 1, right = len;
                while (left <= right){
                    int mid = left + (right - left) / 2;
                    if (ret[mid] < nums[i])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                ret[left] = nums[i];
            }
        }
        return len;
    }
};
// @lc code=end

