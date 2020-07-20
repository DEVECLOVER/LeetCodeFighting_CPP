/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
class Solution {
public:
//问题在于如何更优的解决，好的空间复杂度和时间复杂度
//我们在遍历过程中，想到将0所在的行列的其他元素变为0，但是，就会引入了干扰，怎么办呢
//方法一，将所有0 的位置存储起来，接着遍历
//方法二，能不能不设为0呢，目的是要区分，就是说分类。
//这矩阵根据题目要求可以分为三类：原本就为0：激励源；和0元素在同行或者同列的：受控源；其他的是第三方
// 问题在于元素可能为INT_MAX 或 INT_MIN
//[NAC]
    void GMT(vector<vector<int>>& nums)
    {
        int rows = nums.size();
        int cols = nums[0].size();
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(nums[i][j] == 0)
                {
                    for(int k = 0;k < cols;++k)
                    {
                        if(nums[i][k] != 0)
                            nums[i][k] = INT_MAX;
                    }
                    for(int k = 0;k < rows;++k)
                    {
                        if(nums[k][j] != 0)
                            nums[k][j] = INT_MAX;
                    }
                }
            }
        }
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(nums[i][j] == INT_MAX)
                    nums[i][j] = 0;
            }
        }
    }
    //[AC]
    void GMT2(vector<vector<int>>& nums)
    {
        int rows = nums.size();
        int cols = nums[0].size();
        vector<bool> dprow(rows,false);
        vector<bool> dpcol(cols,false);
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(nums[i][j] == 0)
                {
                    dprow[i] = true;
                    dpcol[j] = true;
                }
            }
        }
        for(int i = 0;i < rows;++i)
        {
            for(int j = 0;j < cols;++j)
            {
                if(dprow[i] || dpcol[j])
                    nums[i][j] = 0;
            }
        }

    }
    void setZeroes(vector<vector<int>>& matrix) 
    {
        //GMT(matrix);
        GMT2(matrix);
    }
};
// @lc code=end

