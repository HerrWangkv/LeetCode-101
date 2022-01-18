/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *prev = head, *node = head->next;
        while (node) {
            if (node->val >= prev->val) {
                prev = node;
                node = node->next;
            }
            else if (node->val <= head->val){
                prev->next = node->next;
                node->next = head;
                head = node;
                node = prev->next;
            }
            else {
                ListNode *tmp = head, *tmp_prev = nullptr;
                while (node->val > tmp->val) {
                    tmp_prev = tmp;
                    tmp = tmp->next;
                }
                tmp_prev->next = node;
                prev->next = node->next;
                node->next = tmp;
                node = prev->next;
            }
        }
        return head;
    }
};
// @lc code=end

