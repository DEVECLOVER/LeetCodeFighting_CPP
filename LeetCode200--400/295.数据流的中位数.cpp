/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
//关键在于，新增一个数，怎么能够减少其他元素的移动次数
//方法一  插入排序
//方法二  优先队列
    /** initialize your data structure here. */
    priority_queue<int> less; //最小堆  大数在前 
    priority_queue<int,vector<int>,greater<int>> more; //最大堆 小数在前
    MedianFinder() {

    }
    
    void addNum(int num) {
        less.push(num);
        more.push(less.top());
        less.pop();
        if(less.size() < more.size())
        {
            less.push(more.top());
            more.pop();
        }
    }
    
    double findMedian() {
        return less.size() > more.size() ? less.top() : (less.top() + more.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

