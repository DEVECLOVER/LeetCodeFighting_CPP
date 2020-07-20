/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
//第一想法  从后向前分析，但是没有具体的思路 [AC]
// 第二遍，这个解法就是自己的第一思路，结果自己当时却没有具体思路，这就是进步啊。不应该没有思路的啊
    bool AntiGMT(vector<int>& nums)
    {
        int len = nums.size() - 1;
        int result = len;
        for(int i = len;i >= 0;--i)
        {
            if(i + nums[i] >= result)
            {
                result = i;
            }
        }
        return (result == 0);
    }
    //思路很好理解，因为是挨个跳的，找到每个点最远跳的位置，如果遍历超过这个位置，说明
    //对应跳跃值为0，无法到达  【AC】
 // 第二遍：这个思路是很好的。很值得借鉴。
    bool GMT(vector<int>& nums)
    {
        int maxlen = 0;
        int len = nums.size();
        for(int i = 0;i < len;++i)
        {
            if(i > maxlen)
                return false;
            else
            {
                maxlen = max(maxlen,i + nums[i]);
            }
        }
        return true;
    }
//第二想法 利用递归回溯  但是超时 思路还是可以的  [NAC]
    bool JumpCore(vector<int>& nums,int index,const int& len)
    {
        if(index + nums[index] >= len)
        {
            return true;
        }
        for(int i = 1;i <= nums[index];++i)
        {
            if(JumpCore(nums,index + i,len))
            {
                return true;
            }
        }
        return false;
    }
    //本质上和上述一样的，【AC】,时间比上述慢
    bool GMT2(vector<int>& nums)
    {
        int index = 0;
        int maxlen = 0;
        int len = nums.size();
        if(len < 2)
            return true;
        int temp;
        for(int index = 0;index < len - 1;)
        {
            for(int i = index;i <= index + nums[index];++i)
            {
                if(i + nums[i] >= len - 1)
                    return true;
                else
                {
                    if(i + nums[i] > maxlen)
                    {
                        maxlen = i + nums[i];
                        temp = i;
                    }
                }
            }
            index = max(index + 1,temp);
            if(index > maxlen)
                return false;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        //return JumpCore(nums,0,len);
         //return AntiGMT(nums);
         //return GMT2(nums);
         return GMT(nums);
    }
};
// @lc code=end

