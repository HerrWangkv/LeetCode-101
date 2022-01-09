/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode *merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r)
            return lists[l];
        if (l > r)
            return nullptr;
        int mid = (l + r) / 2;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode head, *node = &head, *a = l1, *b = l2;
        while (a && b) {
            if (a->val < b->val) {
                node->next = a;
                a = a->next;
            }
            else {
                node->next = b;
                b = b->next;
            }
            node = node->next;
        }
        node->next = (a ? a : b);
        return head.next;
    }
};
// @lc code=end

