/*
 * @lc app=leetcode id=684 lang=cpp
 *
 * [684] Redundant Connection
 */

// @lc code=start
class Solution {
public:
    int Find(vector<int> &parent, int index) {
        if (parent[index] != index)
            parent[index] = Find(parent, parent[index]);
        return parent[index];
    }
    void Union(vector<int> &parent, int index1 ,int index2) {
        parent[Find(parent, index1)] = parent[Find(parent, index2)];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        // Use its own index as parent
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (vector<int> &edge : edges) {
            // if two nodes are not connected, connect them
            if (Find(parent, edge[0]) != Find(parent, edge[1]))
                Union(parent, edge[0], edge[1]);
            // if those two nodes are already connected, that means here is a circle
            else
                return edge;
        }
        return {};
    }
};
// @lc code=end

