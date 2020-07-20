/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if(len < 2)
            return 0;
        int dp_0 = 0;
        int dp_1 = -prices[0] - fee;
        for(int i = 1;i < len;++i)
        {
            dp_0 = max(dp_0,dp_1 + prices[i]);
            dp_1 = max(dp_1,dp_0 - prices[i] - fee);
        }
        return dp_0;

    }
};
// @lc code=end

