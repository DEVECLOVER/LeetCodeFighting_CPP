/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
//对于判断类问题：诸如，是不是子串，是不是子树，
//这里，是不是扰乱集中的元素
//看到这一题，自己之前的信心瞬间溃散了，自己居然实现不了暴力递归，
//分析问题还是不到位啊，教训教训
//【AC】
    bool Violent(string str1,string str2)
    {
        if(str1 == str2)
            return true;
        if(str1.size() != str2.size())
            return false;
        map<char,int> dp;
        int len = str1.size();
        for(int i = 0;i < len;++i)
        {
            ++dp[str1[i]];
            --dp[str2[i]];
        }
        for(auto ele : dp)
            if(ele.second != 0)
                return false;
        //第一个if考察没有交换  第二个if考察交换
        //分析后，存在重叠子问题，所以可以使用备忘录，进而优化到dp
        for(int i = 1;i < len;++i)
        {
            if(Violent(str1.substr(0,i),str2.substr(0,i))
                && Violent(str1.substr(i),str2.substr(i)))
                return true;
            //注意点，s.substr(i)的长度计算 len - i
            if(Violent(str1.substr(0,i),str2.substr(len - i))
                && Violent(str1.substr(i),str2.substr(0,len - i)))
                return true;
        }
        return false;
    }
    //头一次在这里遇到备忘录的设计问题，确保对应的参数是唯一确定的
    bool memorandum(string str1,string str2,map<string,bool>& dp)
    {
        if(dp.count(str1 + str2))
            return dp[str1 + str2];
        if(str1 == str2)
        {
            dp[str1 + str2] = true;
            return true;
        }
        if(str1.size() != str2.size())
        {
            dp[str1 + str2] = false;
            return false;
        }
        map<char,int> dp2;
        int len = str1.size();
        for(int i = 0;i < len;++i)
        {
            ++dp2[str1[i]];
            --dp2[str2[i]];
        }
        for(auto ele : dp2)
            if(ele.second != 0)
            {
                dp[str1 + str2] = false;
                return false;
            }
        for(int i = 1;i < len;++i)
        {
            if(Violent(str1.substr(0,i),str2.substr(0,i))
                && Violent(str1.substr(i),str2.substr(i)))
                {
                    dp[str1 + str2] = true;
                    return true;
                }
            //注意点，s.substr(i)的长度计算 len - i
            if(Violent(str1.substr(0,i),str2.substr(len - i))
                && Violent(str1.substr(i),str2.substr(0,len - i)))
                {
                    dp[str1 + str2] = true;
                    return true;
                }
        }
        dp[str1 + str2] = false;
        return false;
    }
    //将备忘录转换为dp,自己都还是没有清晰的思路，是得要加油努力啊！
    bool isScramble(string s1, string s2) {
        //加了备忘录的运行时间比暴力还慢了呢
        map<string,bool> dp;
        return memorandum(s1,s2,dp);
        //return Violent(s1,s2);
    }
};
// @lc code=end

