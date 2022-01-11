/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool hasCycle(ListNode *head) {
        if (!head)
            return false;
        unordered_set<ListNode *> s;
        ListNode *node = head;
        while (node->next) {
            s.insert(node);
            if (s.count(node->next))
                return true;
            node = node->next;
        }
        return false;
    }
};
// @lc code=end

