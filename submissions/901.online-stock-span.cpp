// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem901.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
#include <vector>
#include <stack>
#include <utility>
using namespace std;
class StockSpanner
{
public:
    vector<int> prices;
    stack<int> stk;
    StockSpanner()
    {
    }
    int next(int price) {
        prices.push_back(price);
        int ret = 1;
        while (!stk.empty() && prices[stk.top()] <= price)
        {
            stk.pop();
            if (stk.empty())
                ret = prices.size();
            else
                ret = prices.size() - stk.top() - 1;
        }
        stk.push(prices.size() - 1);
        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end

