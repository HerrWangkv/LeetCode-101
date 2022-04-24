/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    /* 归并排序
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[cnt++] = nums[i++];
            }
            else {
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[cnt++] = nums[i++];
        }
        while (j <= r) {
            tmp[cnt++] = nums[j++];
        }
        for (int i = 0; i < r - l + 1; ++i) {
            nums[i + l] = tmp[i];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size(), 0);
        mergeSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
    */

    /* 快速排序
    void quickSort(vector<int> &nums, int l, int r) {
        if (l >= r)
            return;
        // 随机选择主元
        int tmp = rand() % (r - l + 1) + l;
        swap(nums[l], nums[tmp]);
        int i = l, j = r;
        int x = nums[i];
        while (i < j) {
            while (i < j && nums[j] >= x)
                --j;
            if (i < j)
                nums[i++] = nums[j];
            while (i < j && nums[i] < x)
                ++i;
            if (i < j)
                nums[j--] = nums[i];
        }
        nums[i] = x;
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
    */
    /* 堆排序
    */
    void max_heapify(vector<int> & nums, int start, int end) {
        int dad = start;
        int son = 2 * dad + 1;
        while (son <= end) {
            if (son + 1 <= end && nums[son + 1] > nums[son])
                ++son;
            if (nums[dad] > nums[son])
                return;
            else {
                swap(nums[dad], nums[son]);
                dad = son;
                son = 2 * son + 1;
            }
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        for (int i = n / 2; i >= 0; --i) {
            max_heapify(nums, i, n - 1);
        }
        for (int i = n - 1; i >= 0; --i) {
            swap(nums[0], nums[i]);
            max_heapify(nums, 0, i - 1);
        }
        return nums;
    }


};
// @lc code=end
