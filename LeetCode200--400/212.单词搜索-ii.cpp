/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Trie
{
    public:
        bool isString;
        Trie* next[26];
        Trie()
        {
            isString = false;
            memset(next,0,sizeof(next));
        }
        void Insert(string word)
        {
            Trie* root = this;
            for(const auto& ch : word)
            {
                if(root->next[ch - 'a'] == nullptr)
                    root->next[ch - 'a'] = new Trie();
                root = root->next[ch - 'a'];
            }
            root->isString = true;
        }
        bool Search(const string& word)
        {
            Trie* root = this;
            for(const auto& ch : word)
            {
                root = root->next[ch - 'a'];
                if(root == nullptr)
                    return false;
            }
            return root->isString;
        }
        bool IsPrefix(const string& prefix)
        {
            Trie* root = this;
            for(const auto& ch : prefix)
            {
                root = root->next[ch - 'a'];
                if(root == nullptr)
                    return false;
            }
            return true;
        }
};
class Solution {
public:
//明天学习如何学习优化回溯  
//和递归联系起来
//传统的dfs算法  暴力回溯吧
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
//利用前缀树  
    void TrieDFS(vector<vector<char>>& board,Trie* root,string word,vector<vector<bool>>& visited,vector<string>& res,int row,int col)
    {
        if(root->Search(word))
        {
            if(res.empty() || find(res.begin(),res.end(),word) == res.end())
                res.push_back(word);
            //想想如果在这个地方加了return 会怎么样  如果单词中有 aaa  aaab  检测到aaa时，便退出了，找不到aaab了
        }
        if(!root->IsPrefix(word))
            return ;
        for(int i = -1;i < 2;++i)
        {
            for(int j = -1;j < 2;++j)
            {
                if(i * j != 0)
                    continue;
                int newi = row + i;
                int newj = col + j;
                if(newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size() && !visited[newi][newj])
                {
                    visited[newi][newj] = true; 
                    TrieDFS(board,root,word + board[newi][newj],visited,res,newi,newj);
                    visited[newi][newj] = false;
                }
            }
        }
    }
    void TrieDFSDeeper(vector<vector<char>>& board,Trie* root,string word,vector<vector<bool>>& visited,vector<string>& res,int row,int col)
    {
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || visited[row][col])
            return;
        word += board[row][col];
        visited[row][col] = true;
        if(root->Search(word))
        {
            if(res.empty() || find(res.begin(),res.end(),word) == res.end())
                res.push_back(word);
            //想想如果在这个地方加了return 会怎么样  如果单词中有 aaa  aaab  检测到aaa时，便退出了，找不到aaab了
        }
        if(!root->IsPrefix(word))
            return ;
        for(int i = -1;i < 2;++i)
        {
            for(int j = -1;j < 2;++j)
            {
                if(i * j != 0)
                    continue;
                TrieDFSDeeper(board,root,word,visited,res,row + i,col + j);
            }
        }
        word = word.substr(0, word.size()-1);
        //word -= board[row][col];
        visited[row][col] = false;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //方法一 暴力DFS
        // vector<string> res;
        // int rows = board.size();
        // int cols = board[0].size();
        // bool* flag = new bool[rows * cols];
        // bool OK = false;
        // for(auto word : words)
        // {
        //     for(int i = 0;i < rows;++i)
        //     {
        //         for(int j = 0;j < cols;++j)
        //             flag[i * cols + j] = false;
        //     }
        //     OK = false;
        //     for(int i = 0;i < rows && !OK;++i)
        //     {
        //         for(int j = 0;j < cols;++j)
        //         {
        //             if(DFS(board,i,j,rows,cols,0,word,flag))
        //             {
        //                 res.push_back(word);
        //                 OK = true; //一旦找到便不再继续搜索
        //                 break;
        //             }
        //         }
        //     }
        // }
        // delete[] flag;
        // return res;
        //利用前缀树
        Trie* root = new Trie();
        for(auto word : words)
        {
            root->Insert(word);
        }
        vector<string> res;
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        //写法一
        // for(int i = 0;i < rows;++i)
        // {
        //     for(int j = 0;j < cols;++j)
        //     {
        //         string word = "";
        //         word += board[i][j];
        //         visited[i][j] = true;
        //         TrieDFS(board,root,word,visited,res,i,j);
        //         visited[i][j] = false;
                   //可以变为一句话
                  //TrieDFS(board,root,"",visited,res,i,j);
        //     }
        // }
        //写法二  有问题 还没发现
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                TrieDFSDeeper(board,root,"",visited,res,i,j);
            }
        }
        return res;

    }
};
// @lc code=end

