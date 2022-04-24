/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1);
        if (!n)
            return ret;
        ret[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (i & 1 == 1)
                ret[i] = ret[i - 1] + 1;
            else
                ret[i] = ret[i / 2];
        }
        return ret;
    }
};
// @lc code=end

