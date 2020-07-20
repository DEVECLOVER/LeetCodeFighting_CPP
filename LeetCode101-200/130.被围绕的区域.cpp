/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
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
    void DFS(vector<vector<char>>& board,int row,int col)
    {
        if(row < 0 || row >= board.size() || col < 0 
            || col >= board[0].size() || board[row][col] == 'X'
            || board[row][col] == '#')
            return;
        board[row][col] = '#';
        for(int i = -1;i < 2;++i)
        {
            for(int j = -1;j < 2;++j)
            {
                if(i * j != 0)
                    continue;
                DFS(board,row + i,col + j);
            }
        }
        // DFS(board,row - 1,col);
        // DFS(board,row + 1,col);
        // DFS(board,row,col -1);
        // DFS(board,row,col + 1);
    }
    void BFS(vector<vector<char>>& board,int row,int col)
    {
        board[row][col] = '#';
        queue<Point*> myqueue;
        myqueue.push(new Point(row,col));
        while(!myqueue.empty())
        {
            Point* pos = myqueue.front();
            myqueue.pop();
            for(int i = -1;i < 2;++i)
            {
                for(int j = -1;j < 2;++j)
                {
                    if(i * j != 0)
                        continue;
                    int newx = pos->x_pos + i;
                    int newy = pos->y_pos + j;
                    if(newx >= 0 && newx < board.size()
                        && newy >= 0 && newy < board[0].size() && board[newx][newy] == 'O')
                        {
                            board[newx][newy] = '#';
                            myqueue.push(new Point(newx,newy));
                        }
                }
            }
        }
    }
    //[AC]
    void GMTDFS(vector<vector<char>>& board)
    {
        int rows = board.size();
        if(rows < 1)
            return;
        int cols = board[0].size();
        // if(rows < 1)   //曾经将这句话放在下面  哎，折磨啊，心浮气躁啊！
        //     return;
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                int flag = (i == 0 || j == 0 || i == rows - 1 || j == cols - 1);
                if(flag && board[i][j] == 'O')
                    DFS(board,i,j);
            }
        }
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
    }
    //[AC]
    void GMTBFS(vector<vector<char>>& board)
    {
        int rows = board.size();
        if(rows < 1)
            return;
        int cols = board[0].size();
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j <cols;++j)
            {
                if(i == 0 || j == 0 || i == rows - 1 || j == cols - 1)
                {
                    if(board[i][j] == 'O')
                        BFS(board,i,j);
                }
            }
        }

        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        //return GMTBFS(board);
        return GMTDFS(board);
    }
};
// @lc code=end

