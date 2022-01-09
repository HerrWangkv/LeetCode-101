/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * */
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp = head, *prev = nullptr;
        int i = 0;
        while (temp)
        {
            if (i == n)
                prev = head;
            else if (i > n)
                prev = prev->next;
            temp = temp->next;
            ++i;
        }
        ListNode *ret;
        if (prev == nullptr) {
            ret = head->next;
            return ret;
        }
        else
            ret = head;
        prev->next = prev->next->next;
        return ret;
    }
};
// @lc code=end

