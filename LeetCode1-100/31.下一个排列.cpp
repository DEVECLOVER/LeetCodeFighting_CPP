/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
// 理清思路  
// 事实上，题目所给的例子不够说明问题，
// 或许你能先到要从后遍历，找到第一个不满前大后小的。然后该怎么交换呢？
    void SwapNum(int& p,int& q)
    {
        if(p == q)
        {
            return;
        }
        int temp = p;
        p = q;
        q = temp;
    }
    void Reverse(vector<int>& nums,int start)
    {
        int end = nums.size() - 1;
        while(start < end)
        {
            SwapNum(nums[start],nums[end]);
            ++start;
            --end;
        }
    }
    void GMT(vector<int>& nums)
    {
        int len = nums.size();
        int preindex = len - 2;
        while(preindex >= 0 && nums[preindex + 1] <= nums[preindex])
        {
            --preindex;
        }
        if(preindex >= 0)
        {
            int lastindex = len - 1;
            while(lastindex > preindex && nums[lastindex] <= nums[preindex])
            {
                --lastindex;
            }
            SwapNum(nums[preindex],nums[lastindex]);
        }
        Reverse(nums,preindex + 1);
    }
    void nextPermutation(vector<int>& nums) {
        GMT(nums);
    }
};
// @lc code=end

