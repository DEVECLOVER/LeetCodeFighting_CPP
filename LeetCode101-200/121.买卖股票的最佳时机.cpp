/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        int dp_day_0 = 0;
        int dp_day_1 = INT_MIN;
        for(int i = 0;i < len;++i)
        {
            dp_day_0 = max(dp_day_0,dp_day_1 + prices[i]);
            dp_day_1 = max(dp_day_1,0 - prices[i]);
        }
        return dp_day_0;


        /*
        int len = prices.size();
        if(len < 2)
        {
            return 0;
        }
        int result = 0;
        int minnum = prices[0];
        for(int i = 1;i < len;++i)
        {
            minnum = min(minnum,prices[i]);
            result = max(result,prices[i] - minnum);
        }
        return result;
        */
    }
};
// @lc code=end

