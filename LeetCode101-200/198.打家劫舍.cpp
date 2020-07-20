/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    //暴力递归 超时 但是这是最直接的思路，
    //之后的备忘录和动态规划都是在这基础上优化的
    int MaxRob(vector<int>& nums,int left)
    {
        if(left >= nums.size())
            return 0;
        return max(MaxRob(nums,left + 1),nums[left] + MaxRob(nums,left + 2));
    }
    int MaxRobDeeper(vector<int>& nums,int left,vector<int>& memo)
    {
        if(left >= nums.size())
            return 0;
        if(memo[left] > 0)
            return memo[left];
        memo[left] = max(MaxRobDeeper(nums,left + 1,memo),nums[left] + MaxRobDeeper(nums,left + 2,memo));
        return memo[left];
    }
    int rob(vector<int>& nums) {

        int len = nums.size();
        int dp[len + 2] = {0};
        //从后向前
        // for(int i = len - 1;i >= 0;--i)
        // {
        //     dp[i] = max(dp[i+1],nums[i] + dp[i + 2]);
        // }
        //从前向后
        for(int i = 0;i < len;++i)
        {
            dp[i + 2] = max(dp[i+1],nums[i] + dp[i]);
        }
        return dp[len + 1];
        // int len = nums.size();
        // vector<int> memo(len,0);
        // return MaxRobDeeper(nums,0,memo);

        //return MaxRob(nums,0);
    }
};
// @lc code=end

