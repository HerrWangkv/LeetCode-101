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
    ListNode *mergeList(ListNode *head1, ListNode *head2) {
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        ListNode *head = new ListNode(0);
        ListNode *node = head;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                node->next = head1;
                head1 = head1->next;
            }
            else {
                node->next = head2;
                head2 = head2->next;
            }
            node = node->next;
        }
        node->next = head1 ? head1 : head2;
        node = head->next;
        delete head;
        return node;
    }
    ListNode* sortList(ListNode* head) {
        //归并排序
        if (!head || !head->next)
            return head;
        //必须使用prev，因为slow才是中点。不然链表长度为2时分不开
        ListNode *fast = head, *slow = head, *prev;
        while(fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast->next)
                fast = fast->next;
        }
        prev->next = nullptr;   
        return mergeList(sortList(head), sortList(slow));
    }
};
// @lc code=end

