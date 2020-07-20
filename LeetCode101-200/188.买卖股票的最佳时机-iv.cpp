/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int MaxInfinit(vector<int>& prices)
    {
        int len = prices.size();
        if(len < 2)
            return 0;
        int dp_0 = 0;
        int dp_1 = -prices[0];
        for(int i = 1;i < len;++i)
        {
            int temp = dp_0; //前一天的收益
            dp_0 = max(temp,dp_1 + prices[i]);
            dp_1 = max(dp_1,temp - prices[i]);
        }
        return dp_0;

    }
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        if(k >= (len >> 1))
            return MaxInfinit(prices);
        int dp[len][k + 1][2] = {0};
        for(int i = 0;i <= k;++i)
        {
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }
        for(int i = 1;i < len;++i)
        {
            for(int j = 1;j <= k;++j)
            {
                dp[i][j][0] = max(dp[i - 1][j][0],dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1],dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[len - 1][k][0];

    }
};
// @lc code=end

