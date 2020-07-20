/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    //暴力回溯  超时  这个方法是借用 前一题的思路
    bool IsSym(string str)
    {
        int left = 0;
        int right = str.size() - 1;
        while(left < right)
        {
            if(str[left] != str[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
    void CutCore(string& str,int index,vector<string>& result,int& minlen)
    {
        if(index >= str.size())
        {
            int length = result.size();
            minlen = min(minlen,length);//不能将result.size() 直接放入min函数中
            return;
        }
        for(int i = index;i < str.size();++i)
        {
            int len = i - index + 1;
            if(!IsSym(str.substr(index,len)))
                continue;
            result.push_back(str.substr(index,len));
            CutCore(str,i + 1,result,minlen);
            result.pop_back();
        }
    }
    int minCut(string s) {
        //回溯算法
        // vector<string> result;
        // int minlen = s.size();
        // if(minlen < 1)
        //     return 0;
        // CutCore(s,0,result,minlen);
        // return minlen - 1;
//看看，这都是自己思维走过的路，吸取经验教训吧
        // int len = s.size();
        // int dp[len][len];
        // memset(dp,0,len * len);
        // for(int i = 0;i < len - 1;++i)
        // {
        //     if(s[i] == s[i + 1])
        //         dp[i][i + 1] = 0;
        //     else
        //         dp[i][i + 1] = 1;
        // }
        // for(int slen = 3;slen <= len;++slen)
        // {
        //     for(int i = 0;i + slen - 1 < len;++i)
        //     {
        //         int j = i + slen - 1;
        //         if(s[i] == s[j])
        //             dp[i][j] = dp[i + 1][j - 1];
        //         else
        //             dp[i][j] = dp[i + 1][j - 1] + 2;
        //     }
        // }
        // return dp[0][len - 1];
        
        int len = s.size();
        if(len < 1)
            return 0;
        int dp[len];
        bool flag[len][len];
        memset(flag,false,len * len);
        for(int i = 0;i < len;++i)
        {
            for(int j = 0;j <= i;++j)
            {
                if(s[i] == s[j] && ((i - j) < 3 || flag[j + 1][i - 1]))
                    flag[j][i] = true;
            }
        }
        // for(int i = 0;i < len;++i)
        //     dp[i] = i;
        // for(int i = 0;i < len;++i)
        // {
        //     if(IsSym(s.substr(0,i + 1)))
        //     {
        //         dp[i] = 0;
        //         continue;
        //     }
        //     for(int j = 0;j < i;++j)
        //     {
        //         if(IsSym(s.substr(j + 1,i - j)))
        //             dp[i] = min(dp[i],dp[j] + 1);
        //     }
        // }
        // return dp[len - 1];


        for(int i = 0;i < len;++i)
            dp[i] = i;
        for(int i = 0;i < len;++i)
        {
            if(flag[0][i])
            {
                dp[i] = 0;
                continue;
            }
            for(int j = 1;j <= i;++j)
            {
                //注意下标的含义
                //flag是从j 到 i，是闭区间
                //dp[j] 是从0到j 也是闭区间 所以下面是取dp[j - 1]  之前写为dp[j] 就报错了
                if(flag[j][i])
                    dp[i] = min(dp[i],dp[j - 1] + 1);
            }
        }
        return dp[len - 1];
        

    }
};
// @lc code=end

