/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution {
public:
//规则1  X的个数一定大于等于O的个数
//规则2  一旦构成赢面，就不再放置旗子
//困难点就是如何快速判断是否赢了。题解中看到有人用了九宫格，真的是很妙，但是扩展到n维呢
    bool Win(vector<string>& board,char op)
    {
        for(int i = 0;i < 3;++i)
        {
            if(op == board[i][0] && board[i][0] == board[i][1] && board[i][1] ==  board[i][2])
                return true;
            if(op == board[0][i] && board[0][i] ==  board[1][i] &&  board[1][i] == board[2][i])
                return true;
        }
        if(op == board[0][0] && board[0][0] ==  board[1][1] &&  board[1][1] == board[2][2])
            return true;
        if(op == board[0][2] && board[0][2] ==  board[1][1] &&  board[1][1] == board[2][0])
            return true;
        return false;
    }
    bool validTicTacToe(vector<string>& board) {
        int Xcount = 0;
        int Ocount = 0;
        for(int i = 0;i < 3;++i)
        {
            for(int j = 0;j < 3;++j)
            {
                if(board[i][j] == 'X')
                    ++Xcount;
                if(board[i][j] == 'O')
                    ++Ocount;
            }
        }
        if(Xcount < Ocount || Xcount - Ocount > 1)
            return false;
        if(Win(board,'X') && Win(board,'O'))
            return false;
        if(Win(board,'X') && Xcount == Ocount)
            return false;
        if(Win(board,'O') && Xcount > Ocount)
            return false;
        return true;
    }
};
// @lc code=end

