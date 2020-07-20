/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
   //暴力 超时  【NAC】
    int Brute(vector<int>& heights)
    {
       int maxsum = 0;
       int len = heights.size();
       for(int i = 0;i < len;++i)
       {
           int curheight = heights[i];
           for(int j = i;j < len;++j)
           {
               curheight = min(curheight,heights[j]);
               maxsum = max(maxsum,curheight * (j - i + 1));
           }
       }
       return maxsum;    
    }

   //单调栈 只与两边相关  很妙的做法  
   //[AC]
   // 总结为什么这么做呢？因为要想求大的面积，我们希望有更高的柱子出现，当后面出现较高的
    // 将他们压入栈中，不是很好想到的解法。
    // 这是局部的有序性。
    int Stack(vector<int>& heights)
    {
        int len = heights.size();
        int maxarea = 0;
        stack<int> con;
        con.push(-1);
        int tempheight = 0;
        for(int i = 0;i < len;++i)
        {
            while(con.top() != -1 && heights[con.top()] >= heights[i])
            {
                tempheight = heights[con.top()];
                con.pop();
                maxarea = max(maxarea,tempheight * (i - con.top() - 1));
            }
            con.push(i);
        }
        while(con.top() != -1)
        {
            tempheight = heights[con.top()];
            con.pop();
            maxarea = max(maxarea,tempheight * (len - con.top() - 1));
        }
        return maxarea;
    }
    int largestRectangleArea(vector<int>& heights) {
        return Stack(heights);
    }
};
// @lc code=end

