/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
class Solution {
public:
    TreeNode* helper(TreeNode *root) {
        if (!root->left && !root->right)
            return root;
        if (!root->left)
            return helper(root->right);
        if (!root->right) {
            root->right = root->left;
            root->left = nullptr;
            return helper(root->right);
        }

        TreeNode *tmp = helper(root->left);
        TreeNode *node  = root->right;
        root->right = root->left;
        root->left = nullptr;
        tmp->right = node;
        return helper(node);
    }
    void flatten(TreeNode* root) {
        if (!root)
            return;
        helper(root);
    }
};
// @lc code=end

