/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
private:
    vector<int> indices;
    vector<int> tree;
    int n;
    void discretize(vector<int> &nums)
    {
        indices.assign(nums.begin(), nums.end());
        sort(indices.begin(), indices.end());
        indices.erase(unique(indices.begin(), indices.end()), indices.end());
        n = indices.size();
    }

    int getIndex(int val) {
        return lower_bound(indices.begin(), indices.end(), val) - indices.begin();
    }

    void intialize() {
        tree.resize(2 * n, 0);
    }
    void update(int val) {
        int id = getIndex(val) + n;
        while (id > 0) {
            tree[id] += 1;
            id /= 2;
        }
    }
    int query(int val) {
        int left = n, right = getIndex(val) + n - 1, ret = 0;
        while (left <= right) {
            if (left & 1) {
                ret += tree[left];
                ++left;
            }
            if (!(right & 1)) {
                ret += tree[right];
                --right;
            }
            left /= 2;
            right /= 2;
        }
        return ret;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        discretize(nums);
        intialize();
        vector<int> ret(nums.size(), 0);
        for (int i = nums.size() - 1; i >= 0; --i) {
            ret[i] = query(nums[i]);
            update(nums[i]);
        }
        return ret;
    }
};
// @lc code=end

