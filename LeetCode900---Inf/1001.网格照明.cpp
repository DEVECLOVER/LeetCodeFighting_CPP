/*
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 */

// @lc code=start
class Solution {
public:
//建立一个对应的照明数组即可，保存光的强度值
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int rows = lamps.size();
        int cols = lamps[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));
        for(auto lamp : lamps)
        {
            for(int i = 0;i < cols;++i)
                ++dp[lamp[0]][i];
            for(int i = 0;i < rows;++i)
                ++dp[i][lamp[1]];
            for()//初始化正反对角线

        }

    }
};
// @lc code=end

