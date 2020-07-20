/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
public:
//这里的规则是什么呢？是矩形，有什么特点呢？
//分解为宽和高
//能联系到柱形的矩形也是很妙的
//[AC]  时间复杂度太高了。重复的不少
    int DpCore(vector<vector<char>>& matrix)
    {
        if(matrix.size() == 0)
            return 0;
        int height = matrix.size();
        int width = matrix[0].size();
        int maxarea = 0;
        vector<vector<int>> dp(height,vector<int>(width,0));
        for(int i = 0;i < height;++i)
        {
            for(int j = 0;j < width;++j)
            {
                if(matrix[i][j] == '1')
                {
                    dp[i][j] = j == 0 ? 1 : dp[i][j - 1] + 1; // 统计位置i,j处左侧连续1的个数
                    int rec = dp[i][j];
                    for(int k = i;k >= 0;--k)
                    {
                        rec = min(rec,dp[k][j]);
                        maxarea = max(maxarea,rec * (i - k + 1));
                    }
                }
            }
        }
        return maxarea;
    }
    int MaxCore(vector<int>& nums)
    {
        stack<int> s;
        int maxarea = 0;
        s.push(-1);
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
            return DpCore(matrix);
    }
};
// @lc code=end

