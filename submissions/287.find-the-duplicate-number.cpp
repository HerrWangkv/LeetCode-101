/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int>& nums) {
        //将nums视为一个链表，node->val = i, node->next->val = nums[i]
        //有重复元素意味着有多个node指向同一个node
        int slow = 0, fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if (slow == fast)
                break;
        }
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
// @lc code=end

