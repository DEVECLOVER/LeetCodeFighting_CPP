/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
class Solution {
public:
//通过这题把计数排序和基数排序  桶排序都得学习一下
    int BySort(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int maxnum = 0;
        for(int i = 0;i < len - 1;++i)
        {
            if(abs(nums[i] - nums[i + 1]) > maxnum)
                maxnum = abs(nums[i] - nums[i + 1]);
        }
        return maxnum;
    }
    int maximumGap(vector<int>& nums) {
        return BySort(nums);
    }
};
// @lc code=end

