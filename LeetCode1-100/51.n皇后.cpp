/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 */

// @lc code=start
class Solution {
public:
    bool IsValid(vector<string>& board,int row,int col)
    {
        for(int i = 0;i < row;++i)
        {
            if(board[i][col] == 'Q')
            {
                return false;
            }
        }
        for(int i = row - 1,j = col - 1;i >= 0 && j >= 0;--i,--j)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }
        for(int i = row - 1,j = col + 1;i >= 0 && j < board.size();--i,++j)
        {
            if(board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void QueueCore(vector<vector<string>>& result,vector<string>& board,int row,const int& size)
    {
        if(row == size)
        {
            result.push_back(board);
            return;
        }
        for(int i = 0;i < size;++i)
        {
            if(!IsValid(board,row,i))
            {
                continue;
            }
            board[row][i] = 'Q';
            QueueCore(result,board,row + 1,size);
            board[row][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n,string(n,'.'));
        QueueCore(result,board,0,n);
        return result;

    }
};
// @lc code=end

