/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    bool IsValid(vector<vector<int>>& grid,int row,int col)
    {
        for(int i = 0;i < row;++i)
            if(grid[i][col])
                return false;
        for(int i = row - 1,j = col - 1;i >= 0 && j >= 0;--i,--j)
            if(grid[i][j])
                return false;
        for(int i = row - 1,j = col + 1;i >= 0 && j < grid.size();--i,++j)
            if(grid[i][j])
                return false;
        return true;
    }
    void QueenCore(vector<vector<int>>& grid,int index,int& count)
    {
        if(index == grid.size())
        {
            ++count;
            return ;
        }
        //关键在于下一步回溯时，叠加的量是什么
        //这里变化的行数，每次面对都是同样的列数选择
        //也就是说理清思路
        for(int i = 0;i < grid.size();++i)
        {
            if(!IsValid(grid,index,i))
                continue;
            grid[index][i] = 1;
            QueenCore(grid,index + 1,count);
            grid[index][i] = 0;
        }
    }
    int totalNQueens(int n) {
        vector<vector<int>> grid(n,vector<int>(n,0));
        int count = 0;
        QueenCore(grid,0,count);
        return count;
    }
};
// @lc code=end

