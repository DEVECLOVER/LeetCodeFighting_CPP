/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    struct Point
    {
        public:
            int x_pos;
            int y_pos;
            Point(int x,int y):x_pos(x),y_pos(y)
            {

            }
    };
//类似曼哈顿距离，利用BFS，每经过一层，距离加一，在这里就是时间加一
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Point*> myqueue;
        int rows = grid.size();
        int cols = grid[0].size();
        int count1 = 0;
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(grid[i][j] == 2)
                    myqueue.push(new Point(i,j));
                if(grid[i][j] == 1)
                    ++count1;
            }
        }
        int dp[] = {-1,0,1,0,-1};
        int count = 0;
        while(!myqueue.empty())
        {
            int len = myqueue.size();
            ++count;
            for(int i = 0;i < len;++i)
            {
                Point* curpoint = myqueue.front();
                myqueue.pop();
                for(int j = 0;j < 4;++j)
                {
                    int newx = curpoint->x_pos + dp[j];
                    int newy = curpoint->y_pos + dp[j + 1];
                    //居然把 newx写成了newy 该死！
                    if(newx >= 0 && newx < rows && newy >= 0 && newy < cols && grid[newx][newy] == 1)
                    {
                        --count1;
                        grid[newx][newy] = 2;
                        myqueue.push(new Point(newx,newy));
                    }
                }
            }
        }
        //如何避免再次遍历呢？添加一个变量，统计 1的数量，然后在BFS中减去，看看最后是否为0即可
        // for(int i = 0;i < rows;++i)
        // {
        //     for(int j = 0;j < cols;++j)
        //         if(grid[i][j] == 1)
        //             return -1;
        // }
        return count1 ? - 1 : (count ? count - 1 : 0);//主要是针对grid中全为0 的情况，此时count不用减1，因为没有进入while循环

    }
};
// @lc code=end

