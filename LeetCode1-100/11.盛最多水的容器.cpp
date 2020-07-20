/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
//[AC]
//关键就在于左右指针如何移动，因为开始时，宽度最大，所以要想产生更大的面积，只有里面的柱子高度变大时才移动
// 这么一来就好了，朝大的那一方移动。
//刚开始自己还想着两边都移动呢？这是没有必要的。光在脑子里想也是不行的，还是要画图细致分析。
    int GMT(vector<int>& height)
    {
        int left = 0;
        int right = height.size() - 1;
        int sum = 0;
        while(left < right)
        {
            sum = max(sum,min(height[left],height[right]) * (right - left));
            if(height[left] < height[right])
                ++left;
            else
            {
                --right;
            }
        }
        return sum;
    }
    int Old(vector<int>& height)
    {
        int maxnum = 0;
        int left = 0;
        int right = height.size() - 1;
        while(left < right)
        {
            maxnum = max(maxnum,min(height[left],height[right]) * (right - left));
            if(height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return maxnum;
    }
// 拿到这个题目第一想法是什么呢？暴力穷举吗？
//未尝不可，但是这是没有分析问题，没有抓住事物之间的联系。非常不高效的。
    int maxArea(vector<int>& height) {
        return GMT(height);
    }
};
// @lc code=end

