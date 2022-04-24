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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 返回 p 或 q 
        if (!root || root ==  p || root ==  q)
            return root;
        // l 和 r 只要不为空，则说明该子节点是 p 或 q 的祖先
        TreeNode *l = lowestCommonAncestor(root->left,  p,  q);
        TreeNode *r = lowestCommonAncestor(root->right,  p,  q);
        // l 和 r 均空，说明该树中不存在pq
        // l 和 r 有一个为空，说明 p 和 q 都在另一子树里。且由于递归，返回的就是最近祖先
        if (!l || !r)
            return l ? l : r;
        // 左右子树都是，说明一边一个，则根节点为最近祖先
        return root;
    }
};
// @lc code=end

