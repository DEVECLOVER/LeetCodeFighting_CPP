/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
//双端队列 理清执行过程
//这就是问题所在，不能存入元素，而是存入下标
//目的在于计算个数
    vector<int> UglyCode(vector<int>& nums,int k)
    {
        vector<int> res;
        deque<int> mydeque;
        // 吸取教训
        int len = nums.size();
        for(int i = 0;i < k;++i)
        {
            while(!mydeque.empty() && nums[i] > mydeque.back())
                mydeque.pop_back();
            mydeque.push_back(nums[i]);
        }
        res.push_back(mydeque.front());
        for(int i = k;i < len;++i)
        {
            while(!mydeque.empty() && mydeque.size() >= k)
                mydeque.pop_front();
            while(!mydeque.empty() && nums[i] > mydeque.back())
                mydeque.pop_back();
            mydeque.push_back(nums[i]);
            res.push_back(mydeque.front());
        }
        return res;
    }
    vector<int> GMT_Deque(vector<int>& nums,int k)
    {
        vector<int> res;
        deque<int> mydeque;
        int len = nums.size();
        for(int i = 0;i < k;++i)
        {
            while(!mydeque.empty() && nums[i] > nums[mydeque.back()])
                mydeque.pop_back();
            mydeque.push_back(i);
        }
        res.push_back(nums[mydeque.front()]);
        for(int i = k;i < len;++i)
        {
            // 注意,下述两步操作的顺序，只有先判断是否个数是否过量，接着额才能添加数据
            //因为存入的是下标，便可以直接通过下标计算得到元素个数
            if(!mydeque.empty() && mydeque.front() == i - k) 
                mydeque.pop_front();
            while(!mydeque.empty() && nums[i] > nums[mydeque.back()])
                mydeque.pop_back();
            mydeque.push_back(i);
            res.push_back(nums[mydeque.front()]);
        }
        return res;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        return GMT_Deque(nums,k);
    }
};
// @lc code=end

