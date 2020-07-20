/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> dp(len,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i < len;++i)
            dp[i] = cost[i] + min(dp[i - 1],dp[i - 2]);
        return min(dp[len - 1],dp[len -2]);
    }
};
// @lc code=end

