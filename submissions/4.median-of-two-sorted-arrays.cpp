/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0, count = 0;
        int curr = 0, prev = 0;
        while (i < m && j < n && count <= (m + n) / 2) {
            prev = curr;
            if (nums1[i] < nums2[j]) {
                curr = nums1[i];
                ++i;
            }
            else {
                curr = nums2[j];
                ++j;
            }
            ++count;
        }
        while (count <= (m + n) / 2) {
            prev = curr;
            if (i == m) {
                curr = nums2[j];
                ++j;
            }
            else {
                curr = nums1[i];
                ++i;
            }
            ++count;
        }
        if ((m + n) & 1) {
            return curr;
        }
        else {
            return static_cast<double>(prev + curr) / 2.0;
        }
    }
};
// @lc code=end

