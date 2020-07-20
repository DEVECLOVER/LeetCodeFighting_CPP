/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 朋友圈
 */

// @lc code=start
class UnionFind
{
    public:
        int length;
        vector<int> parent;
        vector<int> size;
        UnionFind(const int num)
        {
            length = num;
            for(int i = 0;i < num;++i)
            {
                parent.push_back(i);
                size.push_back(1);
            }
        }
        int Find(int x)
        {
            while(parent[x] != x)
            {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }
        void Union(int p,int q)
        {
            int proot = Find(p);
            int qroot = Find(q);
            if(proot == qroot)
                return;
            if(size[proot] > size[qroot])
            {
                parent[qroot] = proot;
                size[proot] += size[qroot];
            }
            else
            {
                parent[proot] = qroot;
                size[qroot] += size[proot];
            }
            --length;
            
        }
        bool Connected(int p,int q)
        {
            return Find(p) == Find(q);
        }
        int Length()
        {
            return length;
        }
};

class Solution
 {
    public:
    // 因为矩阵为对称矩阵，所以并没有使用四方向数组
    // 这个DFS方法也是很好的，深度判断即可
    void DFS(vector<vector<int>>& grid,int row,vector<bool>& dp)
    {
        for(int i = 0;i < grid.size();++i)
        {
            if(grid[row][i] && !dp[i])
            {
                dp[i] = true;
                DFS(grid,i,dp);
            }
        }
      
    }
    int DFSGMT(vector<vector<int>>& M)
    {
        //DFS
        int count = 0;
        int rows = M.size();
        vector<bool> dp(rows,false);
        for(int i = 0;i < rows;++i)
        {
            if(!dp[i])
            {
                ++count;
                DFS(M,i,dp);
            }
        }
        return count;
    }
    int UnionGMT(vector<vector<int>>& M)
    {
        int num = M.size();
        UnionFind* uf = new UnionFind(num);
        for(int i = 0;i < num;++i)
        {
            for(int j = 0;j < i;++j)
            {
                if(M[i][j])
                    uf->Union(i,j);
            }
        }
        return uf->Length();
    }
    int findCircleNum(vector<vector<int>>& M) {
        //return UnionGMT(M);
        return DFSGMT(M);
    }
};
// @lc code=end
    
