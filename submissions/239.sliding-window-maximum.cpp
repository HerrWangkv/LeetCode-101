/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
#include <queue>
#include <deque>
#include <utility>
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /* 优先队列解法
        int n = nums.size();
        //默认较大元素优先
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ret{q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            //如果队首元素不在窗口内，删除
            while (q.top().second <= i - k)
                q.pop();
            ret.push_back(q.top().first);
        }
        return ret;
        */

       // 单调队列解法
        // 窗口内后入队的元素如果最大，先入队的元素就没有意义了，可以建立一个单调递减队列
        // 如果队列最大元素已经在窗口外了，该元素也不再有意义了。
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
        }
        vector<int> ret{nums[q.front()]};
        for (int i = k; i < n; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
            while (q.front() <= i - k)
                q.pop_front();
            ret.push_back(nums[q.front()]);
        }
        return ret;
    }
};
// @lc code=end

