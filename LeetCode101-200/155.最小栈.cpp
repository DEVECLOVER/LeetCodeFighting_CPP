/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
//理清思路 一次过  【AC】
    stack<int> primary;
    stack<int> auxiliary;
    MinStack() {

    }
    
    void push(int x) {
        primary.push(x);
        if(auxiliary.empty() || auxiliary.top() >= x)
            auxiliary.push(x);
    }
    
    void pop() {
        int num = primary.top();
        primary.pop();
        if(num <= auxiliary.top())
            auxiliary.pop();
    }
    int top() {
        return primary.top();
    }
    
    int getMin() {
        return auxiliary.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

