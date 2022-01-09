/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int prev = 1, current = 2;
        for (int i = 2; i < n; ++i) {
            int temp = prev + current;
            prev = current;
            current = temp;
        }
        return current;
    }
};
// @lc code=end

