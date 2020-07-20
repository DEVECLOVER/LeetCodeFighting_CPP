/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
//方法一：暴力回溯  指数级别  自顶向下
//方法二  动态规划  自底向上
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1,0);
        int len = coins.size();
        for(int i = 1;i <= amount;++i)
        {
            dp[i] = INT_MAX;
            for(auto coin : coins)
            {
                if(coin <= i && dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i],dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
// @lc code=end

