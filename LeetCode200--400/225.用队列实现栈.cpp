/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
public:
//都不是很简洁，用队列实现栈，比原问题更复杂。
//思路倒不是很复杂，但不是很巧妙
//[AC]
    queue<int> single;
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        single.push(x);
        int len = single.size();
        for(int i = 0;i < len - 1;++i)
        {
            single.push(single.front());
            single.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num = single.front();
        single.pop();
        return num;
    }
    
    /** Get the top element. */
    int top() {
        return single.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return single.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

