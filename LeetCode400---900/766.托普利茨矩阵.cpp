/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
public:
// 居然自作聪明的写下了如下的解法，难道不可以一次性判断吗？
// [AC]
    bool GMT(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if(rows < 2 && cols < 2)
            return true;
        for(int i = 0;i < cols;++i)
        {
            for(int j = 1;j < rows && i + j < cols;++j)
            {
                if(matrix[0][i] != matrix[j][j + i])
                    return false;
            }
        }
        for(int i = 1;i < rows;++i)
        {
            for(int j = 1;j < cols &&  i + j < rows;++j)
            {
                if(matrix[i][0] != matrix[i + j][j])
                    return false;
            }
        }
        return true;
    }
    bool GMT3(vector<vector<int>>& matrix)
    {
        int height = matrix.size();
        int width = matrix[0].size();
        if(height < 2 || width < 2)
            return true;
        for(int i = 0;i < height - 1;++i)
        {
            for(int j = 0;j < width - 1;++j)
            {
                if(matrix[i][j] != matrix[i + 1][j + 1])
                    return false;
            }
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        //return GMT(matrix);
        return GMT3(matrix);
    }
};
// @lc code=end

