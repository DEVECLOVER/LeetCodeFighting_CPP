/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */

// @lc code=start
class Solution {
public:
//how to use union find method to solve it 
// the key point: merge with the edge pint 
    bool IsValid(vector<vector<int>>& A,const int& rows,const int& cols,int row,int col)
    {
        if(row >= 0 && row < rows && col >= 0 && col < cols && A[row][col])
            return true;
        return false;
    }
    void DFS(vector<vector<int>>& A,const int& rows,const int& cols,int row,int col)
    {
        int dp[] = {-1,0,1,0,-1};
        if(IsValid(A,rows,cols,row,col))
        {
            A[row][col] = 0;
            for(int i = 0;i < 4;++i)
                DFS(A,rows,cols,row + dp[i],col + dp[i + 1]);
        }
    }
    int numEnclaves(vector<vector<int>>& A) {
        int rows = A.size();
        int cols = A[0].size();
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(i == 0 || j == 0 || i == rows - 1 || j == cols - 1)
                    DFS(A,rows,cols,i,j);
            }
        }
        int count = 0;
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(A[i][j])
                    ++count;
            }
        }
        return count;
    }
};
// @lc code=end

