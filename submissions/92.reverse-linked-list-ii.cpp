/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverse(ListNode* head) {
        // reverse the whole linked list
        if (!head)
            return nullptr;
        // head1 is the new head of the reversed linked list
        // head2 is the head of not yet reversed linked list
        ListNode *head1 = head, *head2 = head->next;
        head1->next = nullptr;
        while (head2)
        {
            ListNode *tmp = head2->next;
            head2->next = head1;
            head1 = head2;
            head2 = tmp;
        }
        return head1;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *newHead = new ListNode(0, head);
        ListNode *nodeMm1 = newHead, *nodeM = head;
        for (int i = 1; i < m; ++i) {
            nodeMm1 = nodeM;
            nodeM = nodeM->next;
        }
        ListNode *nodeN = nodeM, *nodeNp1 = nodeM->next;
        for (int i = m; i < n; ++i) {
            nodeN = nodeNp1;
            nodeNp1 = nodeNp1->next;
        }
        nodeN->next = nullptr;
        nodeMm1->next = reverse(nodeM);
        // nodeM is the new tail
        nodeM->next = nodeNp1;
        ListNode *ret = newHead->next;
        delete newHead;
        return ret;
    }
};
// @lc code=end

