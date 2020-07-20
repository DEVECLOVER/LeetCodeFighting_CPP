/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int Map(vector<int>& nums)
    {
        int len = nums.size();
        for(int i = 0;i < len;++i)
        {
            // 因为是最小整数，借用下标。即对用了键值对
            while(nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i])
                swap(nums[i],nums[nums[i] - 1]);
        }
        for(int i = 0;i < len;++i)
        {
            if(nums[i] != (i + 1))
                return i + 1;
        }
        return len + 1;
    }
    int firstMissingPositive(vector<int>& nums) {
       return Map(nums); 
    }
};
// @lc code=end

