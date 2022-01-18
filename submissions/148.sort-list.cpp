/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        return helper(head, nullptr);
    }
    ListNode* helper(ListNode *head, ListNode*tail) {
        // sort head to tail->prev
        if (!head)
            return nullptr;
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        return merge(helper(head, slow), helper(slow, tail));
    }
    ListNode *merge(ListNode *head1, ListNode *head2) {
        if (!head1 && !head2)
            return nullptr;
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode *ret = new ListNode(), *tail = ret;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                tail->next = head1;
                head1 = head1->next;
                tail = tail->next;
            }
            else {
                tail->next = head2;
                head2 = head2->next;
                tail = tail->next;

            }
        }
        if (head1)
            tail->next = head1;
        else
            tail->next = head2;
        tail = ret->next;
        delete ret;
        return tail;
    }
};
// @lc code=end

