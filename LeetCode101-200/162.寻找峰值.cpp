/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
// 如果是查找所有的呢？只需要两次遍历即可，从前往后和从后往前
//两个vector，一个记录正向遍历时后一个比前一个大的index，另一个记录反向遍历时前一个大于后一个的index
//但是，还是很麻烦的  但却是可行的  【AC】
    int GMT(vector<int>& nums)
    {
        vector<int> direct;
        vector<int> reverse;
        int len = nums.size();
        direct.push_back(0);
        for(int i = 1;i < len;++i)
        {
            if(nums[i] > nums[i - 1])
                direct.push_back(i);
        }
        reverse.push_back(len - 1);
        for(int i = len - 2;i >= 0;--i)
        {
            if(nums[i] > nums[i + 1])
                reverse.push_back(i);
        }
        for(auto num : direct)
        {
            if(find(reverse.begin(),reverse.end(),num) != reverse.end())
                return num;
        }
        return -1;
    }
//看了题解，看到有用二分，细想一想确实可以的，但是如果查找所有的呢
//没有仔细读题，相邻两元素不相等
    int Binary(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] > nums[mid + 1])
                right = mid;
            else
            {
                left = mid + 1;
            }
        }
        return left;  //居然输出了 nums[left],又是害我一阵好找
    }
    int findPeakElement(vector<int>& nums) {
        //return GMT(nums);
        return Binary(nums);
    }
};
// @lc code=end

