/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;
class Solution
{
public:
    static bool cmp(pair<int, int> &m, pair<int, int> &n) {
        return m.second > n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurs;
        for (auto &v : nums)
            ++occurs[v];
            //要求给出cmp函数地址，故cmp需要为static
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto &[num, count] : occurs) {
            if (q.size() == k) {
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            }
            else
                q.emplace(num, count);
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
// @lc code=end

