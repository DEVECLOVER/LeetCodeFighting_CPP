/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
//第一眼想法不是利用栈  水平还有待长进
//应该达到烂熟于胸，各个知识点的适用情况
    vector<int> dailyTemperatures(vector<int>& T) {
        int len = T.size();
        vector<int> dp(len,0);
    //第一眼思路，暴力求解 超时
        // for(int i = len - 2;i >= 0;--i)
        // {
        //     for(int j = i + 1;j < len;++j)
        //     {
        //         if(T[j] > T[i])
        //         {
        //             dp[i] = j - i;
        //             break;
        //         }
        //     }
        // }
        // return dp;
    //利用栈  思路很清晰
    stack<int> mystack;
    for(int i = 0;i < T.size();++i)
    {
        while(!mystack.empty() && T[mystack.top()] < T[i])
        {
            dp[mystack.top()] = i - mystack.top();
            mystack.pop();
        }
        mystack.push(i);
    }
    return dp;
    }
};
// @lc code=end

