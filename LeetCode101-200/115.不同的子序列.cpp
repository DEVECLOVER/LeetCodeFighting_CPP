/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        vector<vector<long long >> dp(slen + 1,vector<long long >(tlen + 1,0));
        for(int i = 0;i <= slen;++i)
        {
            dp[i][0] = 1;
        }
        for(int i = 1;i <= slen;++i)
        {
            for(int j = 1;j <= tlen;++j)
            {
                //这个转移方程 好好思考  没事多想想 
                dp[i][j] = dp[i - 1][j];
                if(s[i - 1] == t[j - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[slen][tlen];

    }
};
// @lc code=end

