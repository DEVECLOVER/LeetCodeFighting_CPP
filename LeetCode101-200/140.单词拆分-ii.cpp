/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
//参见IP地址的操作即可  原字符串的substr
//对于字典遍历即可  采用
//因为今天都在做回溯，忘记了动态规划，实际上，一般都是从暴力回溯到备忘录递归 再到动规的
//上一题的单词接龙也是这个优化模式
    vector<string> DpCore(string s,vector<string>& wordDict)
    {
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
    vector<string> wordBreak(string s, vector<string>& wordDict) {

    }
};
// @lc code=end

