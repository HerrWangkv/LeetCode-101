/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
#include <string>
#include <queue>
using namespace std;
class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "N";
        string ret;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (!node)
                ret += "N,";
            else {
                ret += to_string(node->val) + "," ;
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string tmp;
        int i = 0;
        while (i < data.size() && data[i] != ',') {
            tmp += data[i];
            ++i;
        }
        ++i;
        if (tmp == "N")
            return nullptr;
        TreeNode *head = new TreeNode(stoi(tmp));
        queue<TreeNode *> q;
        q.push(head);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            string l, r;
            while (data[i] != ',') {
                l += data[i];
                ++i;
            }
            ++i;
            while (data[i] != ',')
            {
                r += data[i];
                ++i;
            }
            ++i;
            TreeNode *left, *right;
            if (l == "N") 
                left = nullptr;
            else {
                left = new TreeNode(stoi(l));
                q.push(left);
            }
            if (r == "N") 
                right = nullptr;
            else {
                right = new TreeNode(stoi(r));
                q.push(right);
            }
            node->left = left;
            node->right = right;
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

