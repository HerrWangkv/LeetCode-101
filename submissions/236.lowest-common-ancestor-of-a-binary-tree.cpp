/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
using namespace std;
class Solution
{
public:
    TreeNode *ret;
    bool helper(TreeNode *root, TreeNode *p, TreeNode *q) {
        //如果包含p或q即返回true
        if (!root)
            return false;
        bool lson = helper(root->left, p, q);
        bool rson = helper(root->right, p, q);
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson)))
            ret = root;
        return lson || rson || root->val == p->val || root->val == q->val;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        ret = root;
        helper(root, p, q);
        return ret;
    }
};
// @lc code=end

