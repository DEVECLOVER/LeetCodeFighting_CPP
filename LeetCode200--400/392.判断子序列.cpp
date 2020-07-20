/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
//递归 DFS   第一想法 【NAC】  超时
//超时原因：t 中存在太多重复字符，对于匹配是不必要的
//可以去掉重复的字符  如何去掉呢？因为s 中也可能存在重复的字符
    bool DFS(string s,string t)
    {
        if(t.empty())
            return s.empty();
        if(s.empty())
            return true;

        // if(s[0] == t[0] && DFS(s.substr(1),t.substr(1)))
        //     return true;
        //总结上述句法与下述的区别  这也是在其他里遇到过的，一定总结好
        if(s[0] == t[0])
            return DFS(s.substr(1),t.substr(1));
        else
            return DFS(s,t.substr(1));
    }
//联系 包含字符的最短子串问题  采用滑动窗口呢？很明显是可以的
//但是对于此题  [AC]
    bool Loop(string s ,string t)
    {
        if(t.empty())
            return s.empty();
        int index = 0;
        for(auto ch : t)
        {
            if(s[index] == ch)
                ++index;
            if(index >= s.size())
                return true;
        }
        return false;
    }
    //[AC]
    bool Sliding(string s,string t)
    {
        int tindex = 0;
        int sindex = 0;
        int tlen = t.size();
        int slen = s.size();
        while(sindex < slen && tindex < tlen)
        {
            if(s[sindex] == t[tindex])
            {
                ++sindex;
                ++tindex;
            }
            else    
                ++tindex;
        }
        return  sindex == slen;
    }
//针对进阶问题，看到一个很好的思路，做到了不变应万变。那就是将自己的界限最大化，无所不包
//联系字典树 [AC]
    bool Com(string s,string t)
    {
        t = ' ' + t;//加上空格符也是很好的思路，因为对于第一个字符
        int len = t.size();
        vector<vector<int>> dp(len,vector<int>(26,0));
        int index = -1;
        for(char ch = 'a'; ch <= 'z';++ch)
        {
            index = -1;//没来一个字符，就要重置一下
            for(int i = len - 1;i >= 0;--i)
            {
                dp[i][ch - 'a'] = index;
                if(ch == t[i])
                    index = i;
            }
        }
        index = 0;
        for(auto ch : s)
        {
            index = dp[index][ch - 'a'];
            if(index == -1)
                return false;
        }
        return true;
    }
    bool isSubsequence(string s, string t) {
        //return Loop(s,t);
        //return Com(s,t);
        return Sliding(s,t);
    }
};
// @lc code=end

