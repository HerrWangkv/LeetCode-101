/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    void max_heapify(vector<int>& nums, int start, int end) {
        int dad = start;
        int son = 2 * start + 1;
        while (son <= end) {
            if (son + 1 <= end && nums[son] < nums[son + 1])
                ++son;
            if (nums[dad] > nums[son])
                return;
            else {
                swap(nums[dad], nums[son]);
                dad = son;
                son = 2 * dad + 1;
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; --i)
            max_heapify(nums, i, n - 1);
        for (int i = n - 1; i >= n - k; --i) {
            swap(nums[0], nums[i]);
            max_heapify(nums, 0, i - 1);
        }
        return nums[n - k];
    }
};
// @lc code=end

