/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int MaxRob(vector<int> nums,int left,int right)
    {
        int dp1 = 0;
        int dp2 = 0;
        int dp3 = 0;
        for(int i = left;i <= right;++i)
        {
            dp3 = max(dp2,nums[i] + dp1);
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp3;
    }
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)
            return nums[0];
        return max(MaxRob(nums,0,len - 2),MaxRob(nums,1,len - 1));
    }
};
// @lc code=end

