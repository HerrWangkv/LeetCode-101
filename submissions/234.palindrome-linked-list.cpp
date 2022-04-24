/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    ListNode *reverseList(ListNode *head) {
        if (!head)
            return nullptr;
        ListNode *head1 = head, *head2 = head->next;
        head->next = nullptr;
        while(head2) {
            ListNode *tmp = head2->next;
            head2->next = head1;
            head1 = head2;
            head2 = tmp;
        }
        return head1;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;
        ListNode *fast = head, *slow = head;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next)
                fast = fast->next;
        }
        // the second half starting from slow can not be longer than the first half
        slow = reverseList(slow);
        while(slow) {
            if (head->val != slow->val)
                return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};
// @lc code=end
