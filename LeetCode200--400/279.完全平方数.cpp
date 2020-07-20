/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        if(n < 4)
            return n;
        int dp[n + 1] = {0};
        for(int i = 1;i <= n;++i)
        {
            dp[i] = i;
            for(int j = 1;j * j <= i;++j)
            {
                dp[i] = min(dp[i],dp[i - j * j] + 1);
            }
        }
        return dp[n];

    }
};
// @lc code=end

