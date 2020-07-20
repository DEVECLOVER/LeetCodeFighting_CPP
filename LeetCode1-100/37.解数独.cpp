/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    bool IsValid(vector<vector<char>>& board,int row,int col,char ch)
    {
        for(int i = 0;i < 9;++i)
        {
            if(board[row][i] == ch || board[i][col] == ch 
                || board[(row / 3) * 3 + i / 3][(col / 3) * 3 + i % 3] == ch)
                return false;
        }
        return true;
    }
    bool BackCore(vector<vector<char>>& board,int row,int col,const int& size)
    {
        if(row == size && col == 0)
            return true;
        //下面这句话是关键，先列再行，同时列清为 0
        if(col == size)
            return BackCore(board,row + 1,0,size);
        // if(row == size)
        //     return true;
        if(board[row][col] != '.')
            return BackCore(board,row,col + 1,size);
        for(char ch = '1';ch <= '9';++ch)
        {
            if(!IsValid(board,row,col,ch))
                continue;
            board[row][col] = ch;
            if(BackCore(board,row,col + 1,size))
                return true;
            board[row][col] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        BackCore(board,0,0,9);
    }
};
// @lc code=end

