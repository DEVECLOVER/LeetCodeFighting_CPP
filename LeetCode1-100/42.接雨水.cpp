/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        //正确的分析问题，找到正确的规律  即某一列的值与两边的值相关，所谓两边并不是相邻的两列，而是两侧的值
        ///之前一直在这一点上困扰。
        //暴力解法
        if(height.size() < 1)
            return 0;
        int res = 0;
        //暴力双循环 超时
        //观察里面的循环 就能发现问题所在了  重复计算太多
        //方法一
        // for(int i = 1;i < height.size() - 1;++i)
        // {
        //     int leftmax = 0;
        //     for(int j = i - 1;j >= 0;--j)
        //         leftmax = max(leftmax,height[j]);
        //     int rightmax = 0;
        //     for(int k = i + 1;k < height.size();++k)
        //         rightmax = max(rightmax,height[k]);
        //     res += (min(leftmax,rightmax) > height[i] ? min(leftmax,rightmax) - height[i] : 0);
        // }
        //方法二   动态规划  即利用上一次结果
        // int len = height.size(); 
        // vector<int> leftmax(len,0);
        // vector<int> rightmax(len,0);
        // for(int i = 1;i < len - 1;++i)
        //     leftmax[i] = max(leftmax[i - 1],height[i - 1]);
        // for(int i = len -2;i >= 1;--i)
        //     rightmax[i] = max(rightmax[i + 1],height[i + 1]);
        // for(int i = 1;i < height.size() - 1;++i)
        // {
        //     int minnum = min(leftmax[i],rightmax[i]);
        //     if(minnum > height[i])
        //         res += (minnum - height[i]);
        // }
        //方法三 如何进一步改进呢？ 这个转化真的很妙
        // int len = height.size();
        // int leftmax = height[0];
        // int rightmax = height[len - 1];
        // int left = 1;
        // int right = len - 2;
        //关键点  取不取等号   
        //虽然存储雨水是从 下标 1 到 -2的，但是比较大小是包含最左和最右的
        //所以下面的是存在问题的
        // while(left <= right)
        // {
        //     if(height[left] < height[right])
        //     {
        //         height[left] >= leftmax ? leftmax = height[left] : res += (leftmax - height[left]);
        //         ++left;
        //     }
        //     else
        //     {
        //         height[right] >= rightmax ? rightmax = height[right] : res += (rightmax - height[right]);
        //         --right;
        //     }
        // }
        // return res;
        //下面的才是正解
        int len = height.size();
        int leftmax = 0;
        int rightmax = 0;
        int left = 0;
        int right = len -1;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                height[left] >= leftmax ? leftmax = height[left] : res += (leftmax - height[left]);
                ++left;
            }
            else
            {
                height[right] >= rightmax ? rightmax = height[right] : res += (rightmax - height[right]);
                --right;
            }
        }
        return res;
    }
};
// @lc code=end

