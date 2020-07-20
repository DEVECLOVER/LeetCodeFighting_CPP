/*
 * @lc app=leetcode.cn id=174 lang=cpp
 *
 * [174] 地下城游戏
 */

// @lc code=start
class Solution {
public:
//这种题目苦恼的不是写不出来dp,事实上，dp还是比较容易写出来的
//关键是，如何使用DFS做出来。
    int Dp(vector<vector<int>>& dungeon)
    {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX));
        dp[n][m-1] = dp[n-1][m] = 1;
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                int minn = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(1, minn-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
//非常好的思考思路，这是必须应该想到的，不然DFS就是不过关
    //其中有几点注意点：
    //1.判断条件，不是rows 而是rows -1，这是为了判断方面，进入函数，直接加上值即可
    //如果改为rows,那么退出条件和计算方式就得分类了
    //这个题目非常好，因为，他告诉你，这种情况下剪枝意义是不大的，
    //还有，使用备忘录是无用的，这得仔细分析一番
    //从这里我们也就知道，从左上向右下进行dp,是行不通的
    void DFS(vector<vector<int>>& dungeon,const int& rows,const int& cols,int row,int col,int value,int addnum,int& minnum)
    {
        value += dungeon[row][col];
        if(value <= 0)
        {
            addnum += (abs(value) + 1);
            if(addnum > minnum)
                return ; //提前剪枝，如果已经大于之前最小的了，就没有必要再进行下去了
        }
        if(row == rows - 1 && col == cols - 1)
        {
            minnum = min(minnum,addnum);
            return ;
        }
        //对应的是前序遍历
        if(value <= 0)
        {
            if(row < rows - 1)
                DFS(dungeon,rows,cols,row + 1,col,1,addnum,minnum);
            if(col < cols - 1)
                DFS(dungeon,rows,cols,row,col + 1,1,addnum,minnum);
        }
        else
        {
            if(row < rows - 1)
                DFS(dungeon,rows,cols,row + 1,col,value,addnum,minnum);
            if(col < cols - 1)
                DFS(dungeon,rows,cols,row,col + 1,value,addnum,minnum);
        }
    }
    int PostDFS(vector<vector<int>>& dungeon,const int& rows,const int& cols,int row,int col)
    {
        if(row == rows - 1 && col == cols - 1)
        {
            if(dungeon[row][col] > 0)
                return 1;
            else
                return abs(dungeon[row][col]) + 1;
        }
        int right = col < cols - 1 ? PostDFS(dungeon,rows,cols,row,col + 1) : INT_MAX;
        int down = row < rows - 1 ? PostDFS(dungeon,rows,cols,row + 1,col) : INT_MAX;
        int need = right < down ? right - dungeon[row][col] : down - dungeon[row][col];
        if(need > 0)
            return need;
        else    
            return 1;
    }
    int MemoDFS(vector<vector<int>>& dungeon,const int& rows,const int& cols,int row,int col,map<pair<int,int>,int>& memo)
    {
        if(row == rows - 1 && col == cols - 1)
        {
            if(dungeon[row][col] > 0)
                return 1;
            else
                return abs(dungeon[row][col]) + 1;
        }
        if(memo.count({row,col}))//这里有一点需要注意，就是没必要使用pair数组，因为目的是确定唯一的 [row,col],可以使用编码 编码为 "row + # + col"即可
            return memo[{row,col}];//当然如果可以编码为 row + col 最简单不过，但是 1 + 2 和 2 + 1 结果一样，也就是不满足双射，即一一对应关系
        //后序遍历
        int right = col < cols - 1 ? MemoDFS(dungeon,rows,cols,row,col + 1,memo) : INT_MAX;
        int down = row < rows - 1 ? MemoDFS(dungeon,rows,cols,row + 1,col,memo) : INT_MAX;
        int need = right < down ? right - dungeon[row][col] : down - dungeon[row][col];
        if(need > 0)
        {
            memo[{row,col}] = need;
            return need;
        }
        else    
        {
            memo[{row,col}] = 1;
            return 1;
        }
    }
    int DpCore(vector<vector<int>>& dungeon)
    {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
    //方法一 【AC】
        // vector<vector<int>> dp(rows + 1,vector<int>(cols + 1,INT_MAX));
        // dp[rows - 1][cols - 1] = dungeon[rows - 1][cols - 1] > 0 ? 1 : abs(dungeon[rows - 1][cols - 1]) + 1;
        // for(int i = rows - 1;i >= 0;--i)
        // {
        //     for(int j= cols - 1;j >= 0;--j)
        //     {
        //         if(i == rows - 1 && j == cols - 1)
        //             continue;
        //         //下面两句话还可以进一步优化
        //         // dp[i][j] = min(dp[i + 1][j],dp[i][j + 1]) - dungeon[i][j];
        //         // if(dp[i][j] <= 0)
        //         //     dp[i][j] = 1;
        //         //如下
        //         dp[i][j] = max(1,min(dp[i + 1][j],dp[i][j + 1]) - dungeon[i][j]);
                    
        //     }
        // }
//方法二  使用自己的优化初始化方法   【AC】
        // vector<vector<int>> dp(rows,vector<int>(cols,0));
        // for(int i = rows - 1;i >= 0;--i)
        // {
        //     for(int j = cols - 1;j >= 0;--j)
        //     {
        //         //一句话就完事了，但是丧失了可读性，这一句包含太多东西，只能是装逼用了
        //         if(i == rows - 1 || j == cols - 1)
        //             dp[i][j] = (i < (rows - 1) ? max(1,dp[i + 1][j] - dungeon[i][j]) : j < (cols - 1) ? max(1,dp[i][j + 1] - dungeon[i][j]) : dungeon[i][j] > 0 ? 1 : 1+ abs(dungeon[i][j]));
        //         else
        //             dp[i][j] = max(1,min(dp[i + 1][j],dp[i][j + 1]) - dungeon[i][j]);
        //     }
        // }

        // return dp[0][0];
//方法三  状态压缩   仔细考察数组值的更新  即是滚动数组
        vector<int> dp(cols + 1,INT_MAX);
        for(int i = rows - 1;i >= 0;--i)
        {
            for(int j = cols - 1;j >= 0;--j)
            {
                if(i == rows - 1 && j == cols - 1)
                    dp[j] = dungeon[i][j] > 0 ? 1 : 1 + abs(dungeon[i][j]);
                else
                    dp[j] = max(1,min(dp[j],dp[j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0];


    }
    //有了上述的思路，转化为Dp数组是再简单不过了
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int minnum = INT_MAX;
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        //初始值，设为1，也就是说，骑士开始要带着一滴血的
        // DFS(dungeon,rows,cols,0,0,1,1,minnum);
        // return minnum;
        // map<pair<int,int>,int> memo;
        // return MemoDFS(dungeon,rows,cols,0,0,memo);

        return DpCore(dungeon);
}
};
// @lc code=end

