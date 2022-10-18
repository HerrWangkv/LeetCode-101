/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:    
    vector<vector<int>> ret;
    void backtracking(vector<int> &num, int pos) {
        if (pos == num.size()) {
            ret.push_back(num);
            return;
        }
        // 如果num[pos]已经与该值互换过，则为避免重复，不应该再次互换
        unordered_set<int> visited;
        int val = num[pos];
        backtracking(num, pos + 1);
        visited.insert(val);
        for (int i = pos + 1; i < num.size(); ++i) {
            if (!visited.count(num[i])) {
                // 类似swap,但保证了pos+1及之后依旧是升序
                num[pos] = num[i];
                num.erase(num.begin() + i);
                num.insert(num.begin() + pos + 1, val);
                backtracking(num, pos + 1);
                int tmp = num[pos];
                num.erase(num.begin() + pos);
                num.insert(num.begin() + i, tmp);
                visited.insert(num[i]);               
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {        
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return ret;
    }
};
// @lc code=end

