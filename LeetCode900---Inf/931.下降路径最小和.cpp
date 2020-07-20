/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution {
public:
//暴力 DFS  【NAC】
//下面的思路就是如何优化 递归了，剪枝呢？
//正如下面所分析的，这个思路和题目要求是无法再剪枝的，过程中无法判断结果
    void DFS(vector<vector<int>>& A,int rows,int row,int col,int value,int& minnum)
    {
        value += A[row][col];
        //第一遍的UglyCode，过度提前剪枝了，事实上只有在最后才能判断，而不是在过程中判断
        //这个和地下城可以在过程中判断是不一样的，吸取教训
        // if(value > minnum)
        //     return;
        //这是前序遍历
        if(row == rows - 1)
        {
            minnum = min(minnum,value);
            return;
        }
        if(row + 1 < rows)
        {
            DFS(A,rows,row + 1,col,value,minnum);
            if(col - 1 >= 0)
                DFS(A,rows,row + 1,col - 1,value,minnum);
            if(col + 1 < rows)
                DFS(A,rows,row + 1,col + 1,value,minnum);
        }
        
    }
//但是 从下到上的递归去没有写出来，很不应该，【NAC】  超时  通过了33例
    int PostDFS(vector<vector<int>> A,int rows,int row,int col,int& minnum)
    {
        if(row + 1 < rows)
        {
            //后序遍历
            int mid = PostDFS(A,rows,row + 1,col,minnum);
            int left = col - 1 >= 0 ? PostDFS(A,rows,row + 1,col - 1,minnum) : INT_MAX;
            int right = col + 1 < rows ? PostDFS(A,rows,row + 1,col + 1,minnum) : INT_MAX;
            //之前一直更改了A[row][col]的值，结果是一直错误，放到vs上调试才发现错误所在
            //哎，伤心啊。还是没有考虑清楚，一定吸取教训，很大的教训
            //A[row][col] += min(min(left,right),mid);
            if(row == 0)
                minnum = min(minnum,A[row][col] + min(min(left,right),mid));
            return (A[row][col] + min(min(left,right),mid));
        }
        return A[row][col];
    }
//优化了下，使用了备忘录  结果还是超时  通过了 42/46  【NAC】
	int PostDFSMemo(vector<vector<int>> A, int rows, int row, int col, int& minnum,map<pair<int,int>,int>& memo)
	{
		if (memo.count({ row,col }))
			return memo[{row, col}];
		if (row + 1 < rows)
		{
			//后序遍历
			int mid = PostDFSMemo(A, rows, row + 1, col, minnum,memo);
			int left = col - 1 >= 0 ? PostDFSMemo(A, rows, row + 1, col - 1, minnum,memo) : INT_MAX;
			int right = col + 1 < rows ? PostDFSMemo(A, rows, row + 1, col + 1, minnum,memo) : INT_MAX;
			if (row == 0)
				minnum = min(minnum, A[row][col] + min(min(left, right), mid));
			memo[{row, col}] = A[row][col] + min(min(left, right), mid);
			return A[row][col] + min(min(left, right), mid);
		}
		memo[{row, col}] = A[row][col];
		return A[row][col];
	}
    //很好想  【AC】
    int DpCore(vector<vector<int>>& nums)
    {
        int minnum = INT_MAX;
        int rows = nums.size();
        vector<vector<int>> dp(rows,vector<int>(rows + 2,INT_MAX));
        //这里不好使用状态压缩
        //可以改用两行的  而不是rows行
        for(int i = rows - 1;i >= 0;--i)
        {
            for(int j = 1;j <= rows;++j)
            {
                if(i == rows - 1)
                    dp[i][j] = nums[i][j - 1];
                else
                    dp[i][j] = min(dp[i + 1][j], min(dp[i + 1][j - 1],dp[i + 1][j + 1])) + nums[i][j - 1];
                if(i == 0)
                    minnum = min(minnum,dp[i][j]);
            }
        }
        return minnum;
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int rows = A.size();
        if(rows < 2)
            return A[0][0];
        int minnum = INT_MAX;
        // for(int i = 0;i < rows;++i)
        //     DFS(A,rows,0,i,0,minnum);
        // for(int i = 0;i < rows;++i)
        //     PostDFS(A,rows,0,i,minnum);
        // map<pair<int,int>,int> memo;
        // for(int i = 0;i < rows;++i)
        //     PostDFSMemo(A,rows,0,i,minnum,memo);
        // return minnum;

        //动态规划解法
        return DpCore(A);
    }
};
// @lc code=end

