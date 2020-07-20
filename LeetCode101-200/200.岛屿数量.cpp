/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
//询问面试官，输入数组可以更改吗
//如果可以的话，就省略了一个标签数组
    bool IsValid(int row,int col,const int rows,const int cols,vector<vector<char>>& grid)
    {
        if(row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == '1')
            return true;
        return false;
    }
    void DFS(vector<vector<char>>& grid,int row,int col,const int rows,int cols)
    {
        // row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size()
        //     && grid[row][col] == '1'
        //int dp[] = {-1,0,1,0,-1};
        if(IsValid(row,col,rows,cols,grid))
        {
            grid[row][col] = '0';
            for(int i = -1;i < 2;++i)
            {
                for(int j = -1;j < 2;++j)
                {
                    if(i * j != 0)
                        continue;
                    DFS(grid,row + i,col + j,rows,cols);
                }
            }
            // for(int i = 0;i < 4;++i)
            //     DFS2(row + dp[i],col + dp[i + 1],rows,cols,grid);
        }
            
    }
//[AC]
    int Test1(vector<vector<char>>& grid)
    {
        int rows = grid.size();
        if(rows < 1)
            return 0;
        int cols = grid[0].size();
        int count = 0;
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(grid[i][j] == '1')
                {
                    ++count;
                    DFS(grid,i,j,rows,cols);
                }
            }
        }
        return count;
    }
    void DFS2(int row,int col,const int rows,const int cols,vector<vector<char>>& grid)
    {
        //居然又是多敲了一个字母
        int dp[] = {-1,0,1,0,-1};
        if(IsValid(row,col,rows,cols,grid))
        {
            grid[row][col] = '0';
            for(int i = 0;i < 4;++i)
                DFS2(row + dp[i],col + dp[i + 1],rows,cols,grid);
        }
    }
// 【AC】
    int countIslands(vector<vector<char>>& grid)
    {
        int count = 0;
        int rows = grid.size();
        if(rows < 1)
            return 0;
        int cols = grid[0].size();
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(grid[i][j] == '1')
                {
                    ++count;
                    DFS2(i,j,rows,cols,grid);
                    //DFS(grid,i,j,rows,cols);
                }
            }
        }
        return count;
    }

    int numIslands(vector<vector<char>>& grid) {
        return countIslands(grid);
        //return Test1(grid);
    }
};
// @lc code=end

