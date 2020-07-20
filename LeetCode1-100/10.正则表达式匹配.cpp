/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
//转化的思想：如果pattern中不存在 *  和 . 该如何判断是否匹配呢？isMatchEasy就是针对这个问题的
//拓展一步，如果pattern中存在.如何判断呢？很容易解决。
//更进一步，如果存在*了呢？自己需要思考那些问题，第一点，判断是否存在*了，两个字符串是否有效。接着就是如何缩减字符串，
//即缩减 0 1 多个字符时，字符串该如何选取。把这两个问题思考清楚，便解决了。
    //不包含通配字符的字符匹配
    bool isMatchEasy(string text,string pattern)
    {
        if(pattern.empty()) 
            return text.empty();
        bool flag = !text.empty() && text[0] == pattern[0];
        //如果加上".""的话，上述flag变为如下即可
        flag = !text.empty() && (text[0] == pattern[0] || pattern[0] == '.');
        return flag && isMatchEasy(text.substr(1),pattern.substr(1));
    }
//暴力递归  【AC】
    bool isMatchCoreDeeper(string s,string p)
    {
        //为什么没有判断s是否为空呢
        if(p.empty())
        {
            return s.empty(); 
        }
        
        //判断长度的条件，有可能在这繁杂的分析中被忽视，很重要
        //从这个逻辑看来，思路想当清晰，很妙
        if(p.length() >= 2 && p[1] == '*')
        {
            if(s[0] == p[0] || (s[0] != '\0' && p[0] == '.'))// if中两个条件交换位置
            {
                //匹配多次（就包含了一次）和 0次（即使前面字符匹配，也可能匹配0次）
                return (isMatchCoreDeeper(s.substr(1),p) || isMatchCoreDeeper(s,p.substr(2)));
            }
            else
            {
                //匹配零次
                return isMatchCoreDeeper(s,p.substr(2));
            }
        }
        else
        {
            if(s[0] == p[0] || (s[0] != '\0' && p[0] == '.'))
            {
                return isMatchCoreDeeper(s.substr(1),p.substr(1));
            }
            else
            {
                return false;
            }
        }
    }
 //【AC】  思考点：1.dummy head 2.转移方程
    bool DpCore(string s ,string p)
    {
        s = ' ' + s;
        p = ' ' + p;
        int slen = s.length();
        int plen = p.length();
        bool dp[slen + 1][plen + 1];
        memset(dp,false,(slen + 1) * (plen + 1)); // memset的使用问题
        dp[0][0] = true;
        //这里有个问题是，两个字符串不是同步移动的，而是全匹配
        for(int i = 1;i <= slen;++i)
        {
            for(int j = 1;j <= plen;++j)
            {
                if(p[j - 1] == '*')
                {
                    if(p[j - 2] != '.' && s[i - 1] != p[j - 2])
                    //0 次
                        dp[i][j] = dp[i][j - 2];
                    else
                        //分别对应 1次 多次 0次（如何理解dp[i - 1][j]表达多次匹配，从末端理解）
                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j] || dp[i][j - 2];
                }
                else if(s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                //这个if对应的else 应该是将dp[i][j]置为false ，因为开始已经初始化为false，便省略了
            }
        }
        return dp[slen][plen];
    }
    bool isMatch(string s, string p) {
        //return isMatchCoreDeeper(s,p);
        return DpCore(s,p);
    }
};
// @lc code=end

