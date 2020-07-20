/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool IsValid(vector<vector<char>>& grid,int row,int col,int rows,int cols,int pathcount,string& str,bool*& flag)
    {
        //注意不要写成  row <= rows  细心啊！！！
        if(row >= 0 && row < rows && 
           col >= 0 && col < cols && grid[row][col] == str[pathcount] && !flag[row * cols + col])
           return true;
        return false;
    }
    bool DFS(vector<vector<char>>& grid,int row,int col,int rows,int cols,int pathcount,string& str,bool*& flag)
    {
        if(str[pathcount] == '\0')
            return true;
        bool ispath = false;
        if(IsValid(grid,row,col,rows,cols,pathcount,str,flag))
        {
            flag[row * cols + col] = true;
            ++pathcount;
            ispath = DFS(grid,row - 1,col,rows,cols,pathcount,str,flag)
                    || DFS(grid,row + 1,col,rows,cols,pathcount,str,flag)
                    || DFS(grid,row,col - 1,rows,cols,pathcount,str,flag)
                    || DFS(grid,row,col + 1,rows,cols,pathcount,str,flag);
            if(!ispath)
            {
                --pathcount;
                flag[row * cols + col] = false;
            }
        }
        return ispath;
    }
    bool UglyCode(vector<vector<char>>& board,string word)
    {
        if(word.empty() || board.empty())
            return false;
        int rows = board.size();
        int cols = board[0].size();
        bool* flag = new bool[rows * cols];
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
                flag[i * cols + j] = false;
        }
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(DFS(board,i,j,rows,cols,0,word,flag))
                {
                    delete[] flag;
                    return true;
                }
            }
        }
        delete[] flag;
        return false;
    }
    bool DFS(int row,int col,int index,const int rows,const int cols,const string word,vector<vector<char>>& board)
    {
        if(index == word.size())
            return true;
        if(row < 0 || row >= rows || col < 0 || col >= cols
            || word[index] != board[row][col])
            return false;
        //上述两个if判断不能颠倒，好好思考
        char mark = board[row][col];
        board[row][col] = '#'; // 节省了flag数组
        bool res = DFS(row - 1,col,index + 1,rows,cols,word,board) || DFS(row + 1,col,index + 1,rows,cols,word,board)
                    || DFS(row,col - 1,index + 1,rows,cols,word,board) || DFS(row,col + 1,index + 1,rows,cols,word,board);
        board[row][col] = mark;
        return res;
    }
    bool BackCore(vector<vector<char>>& board,string word)
    {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(DFS(i,j,0,rows,cols,word,board))
                    return true;
            }
        }
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        //return UglyCode(board,word);
        return BackCore(board,word);
    }
};
// @lc code=end

