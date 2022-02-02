/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution
{
private:
    vector<vector<int>> edges;
    vector<int> preNum;

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = prerequisites.size();
        edges.resize(numCourses);
        preNum.resize(numCourses);
        for (int i = 0; i < n; ++i) {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++preNum[prerequisites[i][0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (preNum[i] == 0)
                q.push(i);
        }
        int visited = 0;
        while (!q.empty())
        {
            ++visited;
            int m = q.front();
            q.pop();
            for (int i : edges[m]) {
                --preNum[i];
                if (preNum[i] == 0)
                    q.push(i);
            }
        }
        return visited == numCourses;
    }
};
// @lc code=end

