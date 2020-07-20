/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
public:
//分析：因为给定的矩阵不一定是方阵，所以转置后的矩阵与原矩阵不一定同型
//所以输出的矩阵有重新开辟空间存储，
//如果是方阵就可以在原矩阵上进行数字交换了
    vector<vector<int>> NewVector(vector<vector<int>>& A)
    {
        int rows = A.size();
        int cols = A[0].size();
        vector<vector<int>> res(cols,vector<int>(rows,0));
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
    vector<vector<int>> DiffVector(vector<vector<int>>& A)
    {
        int rows = A.size();
        int cols = A[0].size();
        if(rows == cols)
        {
            for(int i = 0;i < rows - 1;++i)
            {
                for(int j = i + 1;j < rows;++j)
                {
                    swap(A[i][j],A[j][i]);
                }
            }
            return A;
        }
        vector<vector<int>> res(cols,vector<int>(rows,0));
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        return DiffVector(A);
    }
};
// @lc code=end

