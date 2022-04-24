/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
public:
    // top()为最大值
    priority_queue<int, vector<int>, less<int>> nums_min;
    // top() 为最小值
    priority_queue<int, vector<int>, greater<int>> nums_max;
    
    void addNum(int num) {
        // 发现了比中位数更小的数
        if (nums_min.empty() || nums_min.top() >= num) {
            nums_min.push(num);
            // 要保证左右两半平衡
            if (nums_min.size() > nums_max.size() + 1) {
                nums_max.push(nums_min.top());
                nums_min.pop();
            }
        }
        // 发现了比中位数更大的数
        else {
            nums_max.push(num);
            // 保证奇数个元素时，中位数是nums_min.top()
            if (nums_max.size() > nums_min.size()) {
                nums_min.push(nums_max.top());
                nums_max.pop();
            }
        }
    }
    
    double findMedian() {
        if (nums_min.size() == nums_max.size())
            return (nums_min.top() + nums_max.top()) / 2.0;
        return nums_min.top();        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

