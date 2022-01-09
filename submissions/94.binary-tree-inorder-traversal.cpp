/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
using namespace std;
class Solution
{
public:
    vector<int> ret;
    void helper(TreeNode *node)
    {
        if (!node)
            return;
        helper(node->left);
        ret.push_back(node->val);
        helper(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return this->ret;
    }
};
// @lc code=end

