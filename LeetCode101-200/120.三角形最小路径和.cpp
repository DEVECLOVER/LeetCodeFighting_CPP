/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //自底向上  方法很好想
        // for(int i = triangle.size() - 2;i >= 0;--i)
        // {
        //     for(int j = 0;j < triangle[i].size();++j)
        //     {
        //         triangle[i][j] = min(triangle[i + 1][j],triangle[i + 1][j + 1]) + triangle[i][j];
        //     }
        // }
        // return triangle[0][0];

        //自顶向下
        for(int i = 1;i < triangle.size();++i)
        {
            for(int j = 0;j < triangle[i].size();++j)
            {
                if(j - 1 < 0)
                {
                    triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
                }
                else if(j >= triangle[i - 1].size())
                {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
                }
                else
                {
                    triangle[i][j] = min(triangle[i - 1][j - 1],triangle[i - 1][j]) + triangle[i][j];
                }
            }
        }
        int row = triangle.size() - 1;
        int res = triangle[row][0];
        for(int i = 0;i < triangle[row].size();++i)
            res = min(res,triangle[row][i]);
        return res;
    }
};
// @lc code=end

