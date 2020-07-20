/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
//【AC】  总是困在书写的错误上，思路都是没有问题的
    vector<vector<int>> GMT(int num)
    {
        if(num < 1)
            return vector<vector<int>>();
        if(num == 1)
            return {{1}};
        if(num == 2)
            return {{1},{1,1}};
        vector<vector<int>> res(num);
        res[0] = {1};
        res[1] = {1,1};
        for(int i = 2;i < num;++i)
        {
            int len = res[i - 1].size();
            res[i].push_back(1);
            for(int j = 0;j < len - 1;++j)//居然在这里把j写成了i,哎，犯了多少错误啊
            {
                res[i].push_back(res[i - 1][j] + res[i - 1][j + 1]);
            }
            res[i].push_back(1);
        }
        return res;
    }
    vector<vector<int>> generate(int numRows) {
        return GMT(numRows);
    }
};
// @lc code=end

