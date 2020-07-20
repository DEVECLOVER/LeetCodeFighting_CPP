/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
//题目做的越多，感觉题目就这样，和前面的不同路径和，没有什么区别，只是改变了下要求
//[AC]
    int UglyCode(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        long long dp[rows][cols];
        memset(dp,0,rows * cols);
        dp[0][0] = grid[0][0];
        for(int i = 1;i < cols;++i)
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        for(int i = 1;i < rows;++i)
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        for(int i = 1;i < rows;++i)
        {
            for(int j = 1;j < cols;++j)
            {
                dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][cols - 1];

        // int rows = grid.size();
        // int cols = grid[0].size();
        // long long dp[rows][cols];
        // for(int i = 0;i < rows;++i)
        // {
        //     for(int j = 0;j < cols;++j)
        //     {
        //         if(i == 0 && j == 0)
        //         {
        //             dp[i][j] = grid[i][j];
        //         }
        //         else if(i == 0)
        //         {
        //             dp[i][j] = grid[i][j] + dp[i][j - 1];
        //         }
        //         else if(j == 0)
        //         {
        //             dp[i][j] = grid[i][j] + dp[i - 1][j];
        //         }
        //         else
        //         {
        //             dp[i][j]  = grid[i][j] + min(dp[i - 1][j],dp[i][j - 1]);
        //         }
        //     }
        // }
        // return dp[rows - 1][cols - 1];
    }
//[AC]
    int DpCore(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        //仔细考察执行的过程，完全可以转换为一维数组的。
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(i == 0 || j == 0)
                {
                    //自己的公式用的就是爽啊，简洁优雅
                    dp[i][j] = grid[i][j] + (i > 0 ? dp[i - 1][j] : j > 0 ? dp[i][j - 1] : 0);
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j],dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[rows - 1][cols - 1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        return UglyCode(grid);
        //return DpCore(grid);
    }
};
// @lc code=end

