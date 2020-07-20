/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
//一次过  【AC】
// 第二遍：第一想法也还是这个思路，这就是转化的思想。
    vector<vector<int>> GenPeel(int n)
    {
        int row = 0;
        int col = 0;
        int rows = n;
        int cols = n;
        vector<vector<int>> res(n,vector<int>(n,0));
        int num = 0;
        while(rows && cols)
        {
            for(int i = col;i < col + cols;++i) // 注意点就是下标的操作
                res[row][i] = ++num;
            ++row;
            --rows;
            if(rows < 1)
                break;
            for(int i = row;i < row + rows;++i)
                res[i][col + cols - 1] = ++num;
            --cols;
            if(cols < 1)
                break;
            for(int i = col + cols - 1;i >= col;--i)
                res[row + rows - 1][i] = ++num;
            --rows;
            if(rows < 1)
                break;
            for(int i = row + rows - 1;i >= row;--i)
                res[i][col] = ++num;
            ++col;
            --cols;
        }
        return res;
    }
    vector<vector<int>> generateMatrix(int n) {
        return GenPeel(n);
    }
};
// @lc code=end

