/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return nullptr;
        ListNode *head1 = head, *head2 = head->next;
        head1->next = nullptr;
        while (head2) {
            ListNode *tmp = head2->next;
            head2->next = head1;
            head1 = head2;
            head2 = tmp;
        }
        return head1;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *rhead1 = reverseList(l1);
        ListNode *rhead2 = reverseList(l2);
        ListNode *tail = new ListNode(0), *node = tail;
        int carry = 0;
        while (rhead1 || rhead2) {
            int sum = (rhead1 ? rhead1->val : 0) + (rhead2 ? rhead2->val : 0) + carry;
            ListNode *tmp = new ListNode(sum % 10);
            carry = sum / 10;
            node->next = tmp;
            node = tmp;
            rhead1 = rhead1 ? rhead1->next : nullptr;
            rhead2 = rhead2 ? rhead2->next : nullptr;
        }
        if (carry)
            node->next = new ListNode(carry);
        ListNode *ret = reverseList(tail->next);
        delete tail;
        return ret;
        
    }
};
// @lc code=end

