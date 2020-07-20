/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
//动态规划
//确定规则：只能向下或者向右
//那么：状态转移工程便出来了，这是很明显的
//之前那些问题呢？正则表达式匹配的规则呢？通配符匹配的呢？编辑距离的呢？
//如何分析题意，确定规则呢？好好琢磨啊！这些不是一两句就能彻底解决的，要的不断思考和总结。
//[AC]
    int UglyCode(int m,int n)
    {
        int matrix[101][101];
        for(int i = 1;i <= m;++i)
        {
            matrix[i][1] = 1;
        }
        for(int i = 1;i<= n;++i)
        {
            matrix[1][i] = 1;
        }
        for(int i = 2;i<=m;++i)
        {
            for(int j = 2;j <= n;++j)
            {
                matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
            }
        }
        return matrix[m][n];
    }
    //DP 就是找递推关系，减少重复计算，站在前人的肩上
    int DpCore(int m,int n)
    {
        vector<vector<int>> dp(m + 1,vector<int>(n + 1,0));
        for(int i = 1;i <= m;++i)
        {
            for(int j = 1;j <= n;++j)
            {
                //优化上面的初始化问题
                if(i == 1 || j == 1)
                    dp[i][j] = 1;
                else
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
    int uniquePaths(int m, int n) {
        return DpCore(m,n);
    }
};
// @lc code=end

