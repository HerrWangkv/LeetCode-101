/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
#include <iostream>
using namespace std;
class Solution
{
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pleft, int ileft, int n) {
        if (n == 0)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pleft]);
        if (n == 1)
            return root;
        int i = ileft;
        while (inorder[i] != preorder[pleft])
            ++i;
        root->left = helper(preorder, inorder, pleft + 1, ileft, i - ileft);
        root->right = helper(preorder, inorder, pleft + i - ileft + 1, i + 1, ileft + n - i - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, 0, preorder.size());
    }
};
// @lc code=end

