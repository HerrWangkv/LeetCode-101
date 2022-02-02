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
    bool isPalindrome(ListNode* head) {
        int n = 0;
        ListNode *mid = EndofFirstHalf(head);
        ListNode *end = reverseList(mid->next);
        bool ret = true;
        ListNode *p1 = head, *p2 = end;
        while (ret && p2) {
            if (p1->val != p2->val) {
                ret = false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        mid->next = reverseList(end);
        return ret;
    }
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
    ListNode *EndofFirstHalf(ListNode* head) {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next; //赋值后的fast必不是nullptr
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end
