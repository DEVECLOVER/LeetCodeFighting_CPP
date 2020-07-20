/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
//BinarySearch   先按列再按行 [AC]
    bool Binary(vector<vector<int>>& matrix, int target)
    {
        int rows = matrix.size();
        if(rows < 1)
            return false;
        int cols = matrix[0].size();
        if(cols < 1)
            return false;
        //我已经不想吐槽自己的眼高手低了，居然符号又写错了，又是害我好找啊
        if(matrix[0][0] > target || target > matrix.back().back())
            return false;
        int left = 0;
        int right = rows - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] > target)
                right = mid - 1;
            else
            {
                left = mid + 1;
            }
        }
        int row = left - 1;
        left = 0;
        right = cols - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] > target)
                right = mid - 1;
            else if(matrix[row][mid] < target)
            {
                left = mid + 1;
            }
        }
        return false;
    }
    bool Binary2(vector<vector<int>>& matrix,int target)
    {
        if(matrix.empty() || matrix[0].empty())
            return false;
        if(target < matrix[0][0] || target > matrix.back().back())
            return false;
        int left = 0;
        int right = matrix.size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(matrix[mid][0] == target)
                return true;
            else if(target < matrix[mid][0])
                right = mid - 1;
            else
                left = mid + 1;
        }
        int row = left - 1;
        left = 0;
        right = matrix[0].size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(target == matrix[row][mid])
                return true;
            else if(target < matrix[row][mid])
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return false;
    }
//找规律  【AC】
    bool GMT(vector<vector<int>>& matrix, int target)
    {
        if(matrix.empty())
            return false;
        int rows = matrix.size();
        int col = matrix[0].size() - 1;
        int row = 0;
        while(row < rows && col >= 0)
        {
            if(matrix[row][col] > target)
                --col;
            else if(matrix[row][col] < target)
                ++row;
            else
            {
                return true;
            }
            
        }
        return false;
    }
//上述两种binary虽然在这里通过了，但是实际上是有大问题的，单纯的检查left-1那一行是不够的。
//还要多查几行的。
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //return GMT(matrix,target);
        //return Binary(matrix,target);
        return Binary2(matrix,target);
    }
};
// @lc code=end

