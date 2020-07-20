/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    //暴力递归  自顶向下 太多重复计算  超时
    int dp(const string& word1, const string& word2,int i,int j)
    {
        //第二次做，还想着
        //if(i < 0 && j < 0) 实际上不需要
        //下述这两个结束条件，自己都没有想到 
        if(i < 0)
            return j + 1;
        if(j < 0)
            return i + 1;
        if(word1[i] == word2[j])
            return dp(word1,word2,i - 1,j - 1);
        else
        {
            //分别对应 替换 添加 删除
            return min(dp(word1,word2,i - 1,j - 1),min(dp(word1,word2,i,j - 1),dp(word1,word2,i - 1,j))) + 1;
        }
    }
    //备忘录解法【AC】
    int dpcache(const string& str1,const string& str2,int i,int j,vector<vector<int>>& dp)
    {
        if(i < 0)
            return j + 1;
        if(j < 0)
            return i + 1;
        if(dp[i][j] > 0)
            return dp[i][j];
        if(str1[i] == str2[j])
            dp[i][j] = dpcache(str1,str2,i - 1,j - 1,dp);
        else
            dp[i][j] = min(dpcache(str1,str2,i - 1,j - 1,dp),min(dpcache(str1,str2,i,j - 1,dp),dpcache(str1,str2,i - 1,j,dp))) + 1;
        return dp[i][j];
    }
    //重设dp数组
    int dpcache2(const string& str1,const string& str2,int i,int j,vector<vector<int>>& dp)
    {
        if(i < 0)
        {
            dp[0][j + 1] = j + 1;
            return dp[0][j + 1];
        }
        if(j < 0)
        {
            dp[i + 1][0] = i + 1;
            return dp[i + 1][0];
        }
        if(dp[i + 1][j + 1] > 0)
            return dp[i + 1][j + 1];
        if(str1[i] == str2[j])
            dp[i + 1][j + 1] = dpcache(str1,str2,i - 1,j - 1,dp);
        else
            dp[i + 1][j + 1] = min(dpcache(str1,str2,i - 1,j - 1,dp),min(dpcache(str1,str2,i,j - 1,dp),dpcache(str1,str2,i - 1,j,dp))) + 1;
        return dp[i + 1][j + 1];
    }
    int minDistance(string word1, string word2) {
        word1 = ' ' + word1;
        word2 = ' ' + word2;
        int len1 = word1.size();
        int len2 = word2.size();
        // 不论是赋值为0，还是1，都是有问题，结合前面的子串问题，
        // 总结一下，赋值问题，初始化
        //第一次，追求数量，提出上面的疑问，这次给完美的解决了
        //实际上是行列式计算中的加边法，自己要静下心来画dp图，一切就了然于胸了
        //就像上面所说的，初始值设为0 1 都不能解决问题，设置0 1 是之前做的一些题目的经验，在这里是不适用的
        //画好了dp图，一切就很清晰了
        vector<vector<int>> dp(len1 + 1,vector<int>(len2 + 1,INT_MAX));
        dp[0][0] = 0;
        for(int i = 1;i <= len1;++i)
        {
            for(int j = 1;j <= len2;++j)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i][j - 1],dp[i - 1][j]),dp[i - 1][j - 1]) + 1;
            }
        }
        return dp[len1][len2];



        //*自底向上动态规划[AC]
        //动态规划的关键点
        //初始值设置
        //状态转移函数
        // int len1 = word1.size();
        // int len2 = word2.size();
        // vector<vector<int>> dp(len1 + 1,vector<int>(len2 + 1,0));

        // for(int i = 1;i <= len2;++i)
        //     dp[0][i] = i;
        // for(int i = 1;i <= len1;++i)
        //     dp[i][0] = i;
        // for(int i = 1;i <= len1;++i)
        // {
        //     for(int j = 1;j <= len2;++j)
        //     {
        //         if(word1[i - 1] == word2[j - 1])
        //             dp[i][j] = dp[i - 1][j - 1];
        //         else
        //         {
        //             dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j - 1])) + 1;
        //         }
        //     }
        // }
        // return dp[len1][len2];

        //备忘录解法【AC】
        // if(word1.size() < 1)
        //     return word2.size();
        // if(word2.size() < 1)
        //     return word1.size();
        // int len1 = word1.size();
        // int len2 = word2.size();
        // vector<vector<int>> dp(len1,vector<int>(len2,0));
        // dpcache(word1,word2,len1 - 1,len2 - 1,dp);
        // return dp[len1 - 1][len2 - 1];

        //备忘录解法 重新设置dp数组[AC]
        // int len1 = word1.size();
        // int len2 = word2.size();
        // vector<vector<int>> dp(len1 + 1,vector<int>(len2 + 1,0));
        // dpcache2(word1,word2,len1 - 1,len2 - 1,dp);
        // return dp[len1][len2];
   }
};
// @lc code=end

