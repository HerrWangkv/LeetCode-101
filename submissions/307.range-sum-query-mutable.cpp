/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class NumArray
{
public:
    int n;
    vector<int> data;
    NumArray(vector<int> &nums) : n(nums.size()), data(2 * n, 0)
    {
        for (int i = n, j = 0; i < 2 * n; ++i, ++j)
            data[i] = nums[j];
        for (int i = n - 1; i > 0; --i)
            data[i] = data[2 * i] + data[2 * i + 1];
    }

    void update(int index, int val) {
        index = index + n;
        int tmp = data[index];
        while (index > 0) {
            data[index] += val - tmp;
            index /= 2;
        }
    }

    int sumRange(int left, int right) {
        int ret = 0, l = left + n, r = right + n;
        while (l <= r) {
            if ((l & 1) == 1)
            {
                ret += data[l];
                ++l;
            }
            if ((r & 1) == 0) {
                ret += data[r];
                --r;
            }
            l /= 2;
            r /= 2;
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

