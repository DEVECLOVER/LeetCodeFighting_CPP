/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
//关键在于下标的确定；
    vector<int> Peel(vector<vector<int>>& matrix)
    {
        vector<int> res;
        int rows = matrix.size();
        if(rows < 1)
            return res;
        int cols = matrix[0].size();
        int row = 0;
        int col = 0;
        while(rows && cols)
        {
            for(int i = col;i < col + cols;++i)
                res.push_back(matrix[row][i]);
            ++row;
            --rows;
            if(rows < 1)
                break;
            for(int i = row;i < row + rows;++i)
                res.push_back(matrix[i][col + cols - 1]);
            --cols;
            if(cols < 1)  //娘娘的，我居然在这里多加了一个 ;  害我好找啊！
                break;
            for(int i = cols + col - 1;i >= col;--i)
                res.push_back(matrix[row + rows - 1][i]);
            --rows;
            if(rows < 1)
                break;
            for(int i = row + rows - 1;i >= row;--i)
                res.push_back(matrix[i][col]);
            ++col;
            --cols;
        }
        return res;
    }
	vector<int> PrintMatrix(vector<vector<int>> matrix)
	{
		vector<int> myVector;
		int height = matrix.size();
        if(height < 1)
            return myVector;
		int width = matrix[0].size();
		int row = 0;
		int col = 0;
		while (height > 0 && width > 0)
		{
			for (int i = col; i < col + width; i++)
			{
				myVector.push_back(matrix[row][i]);
			}
			row++;
			height--;
			if (height == 0)
			{
				break;
			}
			for (int i = row; i < row + height; i++)
			{
				myVector.push_back(matrix[i][col + width - 1]);
			}
			width--;
			if (width == 0)
			{
				break;
			}
			for (int i = col + width - 1; i >= col; i--)
			{
				myVector.push_back(matrix[row + height - 1][i]);
			}
			height--;
			if (height == 0)
			{
				break;
			}
			for (int i = row + height - 1; i >= row; i--)
			{
				myVector.push_back(matrix[i][col]);
			}
			col++;
			width--;
		}
		return myVector;
	}
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return Peel(matrix);
        //return PrintMatrix(matrix);
    }
};
// @lc code=end

