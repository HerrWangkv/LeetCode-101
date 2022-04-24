/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
#include <algorithm>
#include <utility>
using namespace std;
class Solution
{
public:
    // 含 / 不含 root
    pair<int, int> helper(TreeNode* root) {
        if (!root)
            return {0, 0};
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        return {root->val + left.second + right.second, max(left.first,left.second) + max(right.first, right.second)};
    }
    int rob(TreeNode* root) {
        pair<int, int> res = helper(root);
        return max(res.first, res.second);
    }
};
// @lc code=end

