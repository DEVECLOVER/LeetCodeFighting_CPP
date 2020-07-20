/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
class Solution {
public:
    //暴力递归 超时 很明显存在重叠子结构
    int LCSCore(string& str1,int index1,string& str2,int index2)
    {
        if(str1[index1] == '\0' || str2[index2] == '\0')
            return 0;
        int res = 0;
        if(str1[index1] == str2[index2])
            res = 1 + LCSCore(str1,index1 + 1,str2,index2 + 1);
        else
            res = max(LCSCore(str1,index1,str2,index2 + 1),LCSCore(str1,index1 + 1,str2,index2));
        return res;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1 + 1,vector<int>(len2 + 1,0));
        for(int i = 0;i < len1;++i)
        {
            for(int j = 0;j < len2;++j)
            {
                if(text1[i] == text2[j])
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1],dp[i + 1][j]);
            }
        }
        return dp[len1][len2];

        //return LCSCore(text1,0,text2,0);
    }
};
// @lc code=end

