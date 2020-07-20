/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
//关于字符串问题：单个字符串的问题（诸如给定一个规则，寻找最优子串 子序列问题）
//涉及到两个字符串的问题：（编辑距离 公共子串、子序列 等）
// 对于对称性的问题，从中间开始展开。
    int AroundCentre(const string& str,int left,int right)
    {
        // 中心扩展法 
        int len = str.size();
        while(left >= 0 && right < len && str[left] == str[right])
        {
            --left;
            ++right;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        //基本动态规划 【AC】
        int size = s.size();
        if(size < 2)
        {
            return s;
        }
        int maxlen = 1;
        int start = 0;
        vector<vector<bool>> dp(size,vector<bool>(size));
        dp[size - 1][size - 1] = true;
        for(int i = 0;i < size - 1;++i)
        {
            dp[i][i] = true;
            if(s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                start = i;
                maxlen = 2;
            }
        }
        //采用dp[i][j]表示字符i到j的回文长度
        //这只是第一步，如何扫描整个字符串呢？
        //就像扫描二维矩阵，有正遍历 反遍历 斜遍历
        //这里就是采用的斜遍历，为什么呢？因为，你得比较两边的元素
        //这里边也不好把长度为2的纳入进来
        for(int len = 3;len <= size;++len)
        {
            for(int index = 0;index + len - 1 < size;++index)
            {
               int end = index + len - 1;
               if(dp[index + 1][end - 1] && s[index] == s[end])
               {
                   dp[index][end] = true;
                   start = index;
                   maxlen = len;
               } 
            }
        }
        return s.substr(start,maxlen);



        /*中心扩展法【AC】
        int start = 0;
        int end = 0;
        int len = 0;
        for(int i = 0;i < s.size();++i)
        {
            int oddlen = AroundCentre(s,i,i);
            int evenlen = AroundCentre(s,i,i+1);
            len = max(max(oddlen,evenlen),len);
            if(len > end - start + 1) // 即新得到的长度大于之前的长度才更新，等于也不更新
            {
                //下述的起止点的位置计算公式
                //分len的长度为奇数还是偶数统一而得
                //start之所以是len-1 ，是因为上述计算偶数中心是按照 (i,i + 1)
                //即start更靠近左边
                //如果按照(i,i-1)，那么 start = i - len >> 1, end = i + (len-1) >> 1 
                start = i - ((len - 1) >> 1); 
                end = i + (len >> 1);
            }
        }
        return s.substr(start,len);
        */

        //动态规划优化【AC】
        // int len = s.size();
        // if(len < 2)
        //     return s;
        // bool dp[len][len];
        // memset(dp,false,len * len);
        // int maxlen = 0;
        // int start = 0;
        // //优化了上述初始化问题，很值得学习
        // for(int i = 0;i < len;++i)
        // {
        //     for(int j = 0;j <= i;++j)
        //     {
        //         if(s[i] == s[j] && ((i - j) < 3 || dp[j + 1][i - 1]))
        //         {
        //             if(i - j + 1 > maxlen)
        //             {
        //                 maxlen = i - j + 1;
        //                 start = j;
        //             }
        //             dp[j][i] = true;
        //         }
        //     }
        // }
        // return s.substr(start,maxlen);

    }
};
// @lc code=end

