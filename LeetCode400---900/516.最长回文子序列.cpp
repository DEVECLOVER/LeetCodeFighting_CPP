/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int len = s.size();
        vector<vector<int>> dp(len,vector<int>(len,0));
        for(int i = 0;i < len;++i)
            dp[i][i] = 1;
        for(int i = len - 1;i >= 0;--i)
        {
            for(int j = i + 1;j < len;++j)
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j-1] + 2;
                else
                {
                    dp[i][j] = max(dp[i][j-1],dp[i + 1][j]);
                }
            }
        }
        return dp[0][len - 1];

    }
};
// @lc code=end

