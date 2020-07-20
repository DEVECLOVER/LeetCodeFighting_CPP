/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution {
public:
    int UglyCode(vector<vector<int>>& obstacleGrid)
    {
        //手写一次代码，花了二十分钟
        //发现的问题，边值问题，如果初始点为障碍的判断
        //整型溢出的问题，刚开始设置为int，溢出了
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        long long dp[rows][cols];
        memset(dp,0,sizeof(dp));
        if(obstacleGrid[0][0])
            return 0;
        dp[0][0] = 1;
        for(int i = 1;i < cols;++i)
            dp[0][i] = obstacleGrid[0][i] == 1? 0 : dp[0][i - 1];
        for(int i = 1;i < rows;++i)
            dp[i][0] = obstacleGrid[i][0] == 1? 0 : dp[i - 1][0];
        for(int i = 1;i < rows;++i)
        {
            for(int j = 1;j < cols;++j)
            {
                if(obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[rows - 1][cols - 1];
    }
    int DpCore(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<long long>> dp(rows,vector<long long>(cols,0));
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(grid[i][j])
                    dp[i][j] = 0;
                else
                {
                    if(i == 0 || j == 0)
                    {
                        //代码是简短了，但是需要思考了，这是自己的首创，以后多多使用，自我感觉良好
                        dp[i][j] = i > 0 ? dp[i - 1][j] : (j > 0 ? dp[i][j - 1] : 1);
                    }
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return DpCore(obstacleGrid);
    }
};
// @lc code=end

