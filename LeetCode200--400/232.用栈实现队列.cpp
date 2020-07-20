/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
//[AC]
//虽然双百AC了，但是pop和peek存在了重复，能不能改进一下呢？
//看了题解，发现不少就是这个解法，应该是很容易想到的。没有难点。
    /** Initialize your data structure here. */
    stack<int> store;
    stack<int> diverse;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        store.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(empty())
            return -1;
        if(diverse.empty())
        {
            while(!store.empty())
            {
                int num = store.top();
                store.pop();
                diverse.push(num);
            }
        }
        int num = diverse.top();
        diverse.pop();
        return num;
    }
    
    /** Get the front element. */
    int peek() {
        if(empty())
            return -1;
        if(diverse.empty())
        {
            while(!store.empty())
            {
                int num = store.top();
                store.pop();
                diverse.push(num);
            }
        }
        return diverse.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return store.empty() && diverse.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

