/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
//只要涉及到添加新数据的，都是用堆，优先队列
//对于数组，排序是第一位的，除非目标对象与元素的下标有关，
//一旦排序了，就会对结果产生影响，这种情况下，便不能排序了
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto num : stones)
            pq.push(num);
        while(pq.size() > 1)
        {
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();\
            pq.pop();
            if(num1 - num2)
                pq.push(num1 - num2);
        }
        return pq.size() > 0? pq.top() : 0;
    }
};
// @lc code=end

