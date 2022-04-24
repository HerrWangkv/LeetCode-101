// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem98.h"

using namespace std;
// @before-stub-for-debug-end

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
using namespace std;
class Solution
{
public:
    long pre = LLONG_MIN; //不能使用INT_MIN,否则单节点[INT_MAX]会输出false
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        if (!isValidBST(root->left))
            return false;
        if (root->val <= pre)
            return false;
        // pre满足中序遍历顺序
        pre = root->val;
        if (!isValidBST(root->right))
            return false;
        return true;
    }
};
// @lc code=end

