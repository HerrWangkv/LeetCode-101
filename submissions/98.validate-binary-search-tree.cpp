/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    vector<int> vec;
    void inorder(TreeNode *root) {
        if (!root)
            return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode *root)
    {
        inorder(root);
        for (int i = 0; i < vec.size() - 1; ++i) {
            if (vec[i] >= vec[i+1])
                return false;
        }
        return true;
    }
};
// @lc code=end

