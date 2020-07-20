/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        int dp_0 = 0;
        int dp_1 = -prices[0];
        int dp_11 = 0;
        for(int i = 1;i < len;++i)
        {
            int temp = dp_0;
            dp_0 = max(dp_0,dp_1 + prices[i]);
            dp_1 = max(dp_1,dp_11 - prices[i]);
            dp_11 = temp;
        }
        return dp_0;

    }
};
// @lc code=end

