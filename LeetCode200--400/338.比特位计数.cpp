/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
//奇数偶数即可
//关键点  dp[i] = dp[i / 2]  这一点没有立马想到 不应该
    vector<int> countBits(int num) {
        vector<int> dp(num + 1,0);
        for(int i = 1;i <= num;++i)
        {
            if(i & 1)
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i >> 1];
        }
        return dp;
        
    }
};
// @lc code=end

