// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem493.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> tmp;
    int helper(vector<int> &data, int l, int r) {
        if (l >= r)
            return 0;
        int mid = l + (r - l) / 2;
        // 单纯考虑两半
        int ret = helper(data, l , mid) + helper(data, mid + 1, r);
        // 此时前后两半都已被排好序了,考虑逆序对两个元素分别在前后两半的可能性
        int i = l, j = mid + 1;
        for (; i <= mid; ++i) {
            while (j <= r && (long long)data[i] > 2 * (long long)data[j]) {
                // 如果前一半的某个元素可以和后一半的某个元素组成逆序对，则前一半的剩余元素也都可以
                ret += mid - i + 1;
                ++j;
            }
        }
        // 对 [l, r]范围进行归并排序
        i = l;
        j = mid + 1;
        int cnt = l;
        while (i <= mid && j <= r) {
            if (data[i] <= data[j])
                tmp[cnt++] = data[i++];
            else {
                tmp[cnt++] = data[j++];
            }
        }
        while (i <= mid) 
            tmp[cnt++] = data[i++];
        while (j <= r)
            tmp[cnt++] = data[j++];
        for (int k = l; k <= r; ++k) {
            
            data[k] = tmp[k];
        }
        return ret;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        tmp.resize(n, 0);
        return helper(nums, 0, n - 1);
    }
};
// @lc code=end

