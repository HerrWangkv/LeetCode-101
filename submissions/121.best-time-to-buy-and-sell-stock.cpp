/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0, n = prices.size(), high = 0;
        for (int i = n - 1; i >= 0; --i) {
            ret = max(ret, high - prices[i]);
            high = max(high, prices[i]);
        }
        return ret;
    }
};
// @lc code=end

