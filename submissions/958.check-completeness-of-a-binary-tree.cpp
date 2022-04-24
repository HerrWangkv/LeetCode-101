/*
 * @lc app=leetcode id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty() && q.front()) {
            TreeNode *node = q.front();
            q.pop();
            q.push(node->left);
            q.push(node->right);
        }
        // 如果BFS先遍历到了空指针，后续所有遍历到的指针都需要是空指针
        while (!q.empty()) {
            if (q.front()) {
                return false;
            }
            q.pop();
        }  
        return true;        
    }
};
// @lc code=end

