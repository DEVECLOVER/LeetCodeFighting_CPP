/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start
class Solution {
public:
//观察  一般性思维方法 
//这类题目和诸如天际线问题还不太一样，没有涉及过多的数据结构和算法知识，
//只是一般性的观察 
//看了题解  大家用的最多的还是二分查找  因为每一行 每一列都是有序的数组
//还是要看一下的，其中还是有很多小技巧的 这些都是细节问题
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        //扫描法
        int rows = matrix.size();
        int cols= matrix[0].size();
        int row = 0;
        int col = cols - 1;
        while(row < rows && col >= 0)
        {
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] > target)
                --col;
            else
                ++row;
        }
        return false;
        
        //二分查找  有问题  待改进
        // int rows = matrix.size();
        // int cols = matrix[0].size();
        // int left = 0;
        // int right = rows * cols - 1;
        // while(left <= right)
        // {
        //     int mid = ((left + right) >> 1);
        //     //这么操作是自己万万想不到的，将二维数组转化为一维，
        //     //但是下标的操作，很值得学习总结
        //     int num = matrix.at(mid / cols).at(mid % cols);
        //     if(num == target)
        //         return true;
        //     //这么操作还是有问题的  
        //     if(num > target)
        //         right = mid - 1;
        //     else   
        //         left = mid + 1;
        // }
        // return false;
    }
};
// @lc code=end

