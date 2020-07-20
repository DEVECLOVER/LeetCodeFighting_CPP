/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        bool dp[len + 1];
        memset(dp,false,len + 1);
        dp[0] = true;
        for(int i = 0;i < len;++i)
        {
            for(int j = i;j < len;++j)
            {
                int len = j - i + 1;
                if(dp[i] && find(wordDict.begin(),wordDict.end(),s.substr(i,len)) != wordDict.end())
                    dp[j + 1] = true;
            }
        }
        return dp[len];

    }
};
// @lc code=end

