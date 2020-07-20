/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    struct Point
    {
        int x_pos;
        int y_pos;
        Point(int x,int y):x_pos(x),y_pos(y)
        {

        }
    };
//BFS 和 动态规划都想到了
//但是对于动态规划，状态转移方程是容易建立的，但是难在如何遍历呢
//因为，某个点是与周围四个点相关联的，而遍历是一个方向的，就是说有周围的点还没遍历到
//看了题解，妙的是，采用了两次不同方向的遍历  覆盖了所有情况 敢想敢做
//【AC】
    void BFS(vector<vector<int>>& matrix,vector<vector<int>>& dp)
    {
        int rows = matrix.size();
        if(rows < 1)
            return;
        int cols = matrix[0].size();
        queue<Point*> myqueue;
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(matrix[i][j] == 0)
                {
                    dp[i][j] = 0;
                    myqueue.push(new Point(i,j));
                }
                
            }
        }
        while(!myqueue.empty())
        {
            Point* curpoint = myqueue.front();
            myqueue.pop();
            for(int i = -1;i < 2;++i)
            {
                for(int j = -1;j < 2;++j)
                {
                    if(i * j != 0)
                        continue;
                    int newx = curpoint->x_pos + i;
                    int newy = curpoint->y_pos + j;
                    //一旦报错 诸如 heap-buffer-overflow on address 0x607000000158
                    //就考虑是数组越界  之前没有加位置判断
                    if(newx < 0 || newx >= rows || newy < 0|| newy >= cols)
                        continue;
                    if(dp[newx][newy] > dp[curpoint->x_pos][curpoint->y_pos] + 1)
                    {
                        dp[newx][newy] = dp[curpoint->x_pos][curpoint->y_pos] + 1;
                        myqueue.push(new Point(newx,newy));
                    }
                }
            }
        }
    }
    //Dp实现
     vector<vector<int>> DpCore(vector<vector<int>>& nums)
    {
        int rows = nums.size();
        int cols = nums[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,rows + cols));
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(nums[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if(i == 0 || j == 0)
                        dp[i][j] = (i ? min(dp[i][j],1 + dp[i - 1][j]) : j ? min(dp[i][j],1 + dp[i][j - 1]) : dp[i][j]);
                    else
                        dp[i][j] = min(dp[i][j],min(dp[i - 1][j],dp[i][j - 1]) + 1);
                }
            }
        }
        for(int i = rows - 1;i >= 0;--i)
        {
            for(int j = cols - 1;j >= 0;--j)
            {
                if(nums[i][j] == 0)
                    continue;
                if(i == rows - 1 || j == cols - 1)
                    dp[i][j] = (i != (rows - 1) ? min(dp[i][j],1 + dp[i + 1][j]) : 
                        j != (cols - 1) ? min(dp[i][j],1 + dp[i][j + 1]) : dp[i][j]);
                else
                    dp[i][j] = min(dp[i][j],min(dp[i + 1][j],dp[i][j + 1]) + 1);
            }
        }
        return dp;
    }
    //【AC】
    vector<vector<int>> OldDp(vector<vector<int>> matrix)
    {
        int rows = matrix.size();
        if(rows < 1)
            return vector<vector<int>>();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,rows + cols)); //因为最大也就是rows + cols
        //左上到右下
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(matrix[i][j] == 0)  //还可以在这里继续加，如果四周存在1 ，对应位置dp设置为1即可
                    dp[i][j] = 0;
                else
                {
                    if(i > 0)
                        dp[i][j] = min(dp[i][j],dp[i - 1][j] + 1);
                    if(j > 0)
                        dp[i][j] = min(dp[i][j],dp[i][j - 1] + 1);
                }
            }
        }
        //右下到左上
        for(int i = rows - 1;i >= 0;--i)
        {
            for(int j = cols - 1;j >= 0;--j)
            {
                if(i < rows - 1)
                    dp[i][j] = min(dp[i][j],dp[i + 1][j] + 1);
                if(j < cols - 1)
                    dp[i][j] = min(dp[i][j],dp[i][j + 1] + 1);
            }
        }
        return dp;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        // int rows = matrix.size();
        // if(rows < 1)
        //     return vector<vector<int>>();
        // int cols = matrix[0].size();
        // vector<vector<int>> dp(rows,vector<int>(cols,rows + cols));
        // BFS(matrix,dp);
        // return dp;


        return DpCore(matrix);
    }
};
// @lc code=end

