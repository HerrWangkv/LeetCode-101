/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret{};
        if (!root)
            return ret;
        queue<TreeNode*> q;
        TreeNode *node = root;
        q.push(node);
        while (!q.empty()) {
            int n = q.size();
            vector<int> temp;
            for (int i = 0; i < n; ++i)
            {
                TreeNode *current = q.front();
                q.pop();
                temp.push_back(current->val);
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};
// @lc code=end

