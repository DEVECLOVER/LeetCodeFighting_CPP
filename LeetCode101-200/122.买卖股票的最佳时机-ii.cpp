/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        int dp_day_0 = 0;
        int dp_day_1 = -prices[0];
        for(int i = 1;i < len;++i)
        {
            int temp = dp_day_0;//代表前一天的收益
            dp_day_0 = max(temp,dp_day_1 + prices[i]);
            dp_day_1 = max(dp_day_1,temp - prices[i]);//第一道没有temp,是因为只允许一次买卖机会
        }
        return dp_day_0;
        // int dp[len][2] = {0};
        // dp[0][0] = 0;
        // dp[0][1] = -prices[0];//第一天持有股票
        // for(int i = 1;i < len;++i)
        // {
        //     dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i]);
        //     dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
        // }
        // return dp[len - 1][0];
    }
};
// @lc code=end

