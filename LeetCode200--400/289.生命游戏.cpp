/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */

// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        //正常思路
        // int rows = board.size();
        // int cols = board[0].size();
        // for(int i = 0;i < rows;++i)
        // {
        //     for(int j = 0;j < cols;++j)
        //     {
        //         for(int k = -1;k < 2;++k)
        //         {
        //             for(int p = -1;p < 2;++p)
        //             {
        //                 if(k == 0 && p == 0)
        //                     continue;
        //                 int newx = i + k;
        //                 int newy = j + p;
        //                 if(newx >= 0 && newx < rows && newy >= 0 && newy < cols)
        //                     board[i][j] += (board[newx][newy] & 1 > 0 ? 2 : 0);
        //             }
        //         }
        //     }
        // }
        // for(int i = 0;i < rows;++i)
        // {
        //     for(int j = 0;j < cols;++j)
        //     {
        //         int num = board[i][j];
        //         if(num == 1 || num == 3)
        //             board[i][j] = 0;
        //         else if(num & 1 && num > 7)
        //             board[i][j] = 0;
        //         else if(num == 6)
        //             board[i][j] = 1;
        //         else 
        //             board[i][j] = num % 2;
        //     }
        // }
        //利用原地更改  位存储信息
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                int sum = 0;
                for(int k = -1;k < 2;++k)
                {
                    for(int p = -1;p < 2;++p)
                    {
                        if(k == 0 && p == 0)
                            continue;
                        int newx = i + k;
                        int newy = j + p;
                        if(newx >= 0 && newx < rows && newy >= 0 && newy < cols)
                            sum += (board[newx][newy] & 1); //只加上最低位
                    }
                }
                // 00  0 末位代表原始的死活，上一位代表最终死活，0 为死  1 为活
                // 01  1
                // 10  2
                // 11  3
                if(board[i][j])
                {
                    if(sum == 2 || sum == 3)
                        board[i][j] = 3;   
                }
                else 
                {
                    if(sum == 3)
                        board[i][j] = 2;
                }
            }
        }
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                board[i][j] >>= 1;
            }
        }


    }
};
// @lc code=end

