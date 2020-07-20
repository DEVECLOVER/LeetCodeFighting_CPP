/*
 * @lc app=leetcode.cn id=1072 lang=cpp
 *
 * [1072] 按列翻转得到最大值等行数
 */

// @lc code=start
class Solution {
public:
// 如何分析问题呢？目标是什么？行全等的值。
// 如何得到行全等？通过列翻转。关键在于求个数最多的。
// 如何保证最多呢？两种可能？原先就是相等的行，或者互补的行。
// 如何快速判断是否相等或者互补呢？因为所给的元素是一位。我们如何组织呢？
// 是不是要专门设计互补的判断方式呢？基于我们组织的数据结构。


// 看题解看到一个很好的方法。思路就是上述的思路，妙处就在如何实践？这种统计方法，很好的。
    int Cool(vector<vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        unordered_map<string,int> hash;
        int res = 0;
        for(int i = 0;i < rows;++i)
        {
            int j = 0;
            string temp = "";
            while(j < cols)
            {
                int k = j + 1;
                while(k < cols && matrix[i][k] == matrix[i][j])
                    ++k;
                temp += to_string(k);
                j = k;
            }
            ++hash[temp];
            res = max(res,hash[temp]);            
        }
        return res;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        return Cool(matrix);
    }
};
// @lc code=end

