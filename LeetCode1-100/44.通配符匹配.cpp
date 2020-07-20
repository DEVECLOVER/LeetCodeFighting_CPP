/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
//分析到 * 的两种作用 
//方法  暴力递归  优化到备忘录  上述都是自顶向下的  再优化到自底向上
//第二次思考时，还是没能清楚的分析到*的匹配方式
//看到状态转移方程便恍然大悟了，太妙了。
    bool isMatch(string s, string p) {
        s = ' ' + s;
        p = ' ' + p;
        int slen = s.size();
        int plen = p.size();
        bool dp[slen + 1][plen + 1];
        memset(dp,false,(slen + 1) * (plen + 1));
        dp[0][0] = true;
        for(int i = 1;i <= slen;++i)
        {
            for(int j = 1;j <= plen;++j)
            {
                if(p[j - 1] == '*')
                {
                    //要么匹配空  要么匹配多个
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                }
                if(p[j - 1] == '?' || s[i - 1] == p[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }
        return dp[slen][plen];
    }
};
// @lc code=end

