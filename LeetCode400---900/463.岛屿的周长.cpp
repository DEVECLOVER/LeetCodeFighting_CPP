/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int count = 0;
        int edge = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        //方向矩阵从二维变为一维，也是很好的，观察和思考
        int dp[] = {-1,0,1,0,-1};
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(grid[i][j] > 0)
                {
                    ++count;
                    // for(int k = -1;k < 2;++k)
                    // {
                    //     for(int p = -1;p < 2;++p)
                    //     {
                            //之前一直困在这里 哎，还是急功近利啊 没有考虑到 k == p == 0的情况
                    //         if(k * p == 0)
                    //         {
                    //             int newx = i + k;
                    //             int newy = j + p;
                    //             if(newx >= 0 && newx < rows && newy >= 0 && newy < cols && grid[newx][newy] > 0)
                    //                 --count;
                    //         }
                    //     }
                    // }
                    for(int k = 0;k < 4;++k)
                    {
                        int newx = i + dp[k];
                        int newy = j + dp[k + 1];
                        if(newx >= 0 && newx < rows && newy >= 0 && newy < cols && grid[newx][newy] > 0)
                            ++edge;
                    }
                }
            }
        }
        return (count << 2) - edge;
    }
};
// @lc code=end

