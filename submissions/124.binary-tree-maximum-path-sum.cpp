/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
using namespace std;
class Solution
{
public:
    int maxSum;
    int helper(TreeNode* root) {
        //返回该节点到叶节点的路径最大和
        if (!root)
            return 0;
        int left = max(0, helper(root->left)), right = max(0, helper(root->right));
        //经过root的pathsum最大值
        this->maxSum = max(this->maxSum, root->val + left + right);
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        this->maxSum = INT_MIN;
        helper(root);
        return this->maxSum;
    }
};
// @lc code=end

