/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        int dp_day_10 = 0;
        int dp_day_11 = -prices[0];
        int dp_day_20 = 0;
        int dp_day_21 = -prices[0];//如果设置为负无穷，无法应对两天的情况。
        for(int i = 1;i < len;++i)
        {
           dp_day_10 = max(dp_day_10,dp_day_11 + prices[i]);
           dp_day_11 = max(dp_day_11,-prices[i]);
           dp_day_20 = max(dp_day_20,dp_day_21 + prices[i]);
           dp_day_21 = max(dp_day_21,dp_day_10 - prices[i]);
        }
        return dp_day_20;
    }
};
// @lc code=end

