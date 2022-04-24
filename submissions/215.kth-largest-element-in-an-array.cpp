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
    void quickSort(vector<int> &vec, int l, int r, int k) {
        if (l == r)
            return;
        int tmp = rand() % (r - l + 1) + l;
        swap(vec[tmp], vec[l]);
        int i = l, j = r;
        int x = vec[i];
        while (i < j) {
            while (i < j && vec[j] >= x) 
                --j;
            if (i < j)
                vec[i++] = vec[j];
            while (i < j && vec[i] < x) 
                ++i;
            if (i < j)
                vec[j--] = vec[i];
        }
        vec[i] = x;
        if (i == k)
            return;
        if (i < k)
            // 如果当前正确索引小于k，则没必要对0-i之间进行排序
            quickSort(vec, i + 1, r, k);
        else
            quickSort(vec, l, i - 1, k);       
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        quickSort(nums, 0, n - 1, n - k);
        return nums[n - k];
    }
};
// @lc code=end

