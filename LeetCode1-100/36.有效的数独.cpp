/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //二维数组  借助位运算降为一维
        // int rows[9][9];
        // int cols[9][9];
        // int soduku[9][9];
        // memset(rows,0,sizeof(rows));
        // memset(cols,0,sizeof(cols));
        // memset(soduku,0,sizeof(soduku));
        // for(int i = 0;i < 9;++i)
        // {
        //     for(int j = 0;j < 9;++j)
        //     {
        //         if(board[i][j] == '.')
        //             continue;
        //         if(++rows[i][board[i][j] - '1'] > 1)
        //             return false;
        //         if(++cols[board[i][j] - '1'][j] > 1)
        //             return false;
        //         if(++soduku[board[i][j] - '1'][(i/3)* 3 + j / 3] > 1)
        //             return false;
        //     }
        // }
        // return true;
        short rows[9];
        short cols[9];
        short soduku[9];
        memset(rows,0,sizeof(rows));
        memset(cols,0,sizeof(cols));
        memset(soduku,0,sizeof(soduku));
        for(int i = 0;i < 9;++i)
        {
            for(int j = 0;j < 9;++j)
            {
                if(board[i][j] == '.')
                    continue;
                int bit = board[i][j] - '1';
                if((rows[i] >> bit) & 1)
                    return false;
                else
                    rows[i] |= (1 << bit);

                if((cols[j] >> bit) & 1)
                    return false;
                else
                    cols[j] |= (1 << bit);

                if((soduku[(i/3)* 3 + j / 3] >> bit) & 1)
                    return false;
                else
                    soduku[(i/3)* 3 + j / 3] |= (1 << bit);
            }
        }
        return true;

        
    }
};
// @lc code=end

