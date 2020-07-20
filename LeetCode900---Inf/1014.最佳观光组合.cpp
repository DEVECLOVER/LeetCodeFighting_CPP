/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
class Solution {
public:
//之前计算绝对值，可以采用二分，因为只和值有关，可以进行排序
//但是这题，计算结果和下标有关，便无法排序了
//脑子就沉在之前的题目中了  
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxnum = 0;
        //暴力解法 超时 
        // for(int i = 0;i < A.size() - 1;++i)
        // {
        //     for(int j = i + 1;j < A.size();++j)
        //     {
        //         maxnum = max(maxnum,(A[i] + A[j] - abs(i - j)));
        //     }
        // }
        // return maxnum;
        
        int premax = A[0];
        for(int i = 1;i < A.size();++i)
        {
            maxnum = max(maxnum,premax + A[i] - i);
            premax = max(premax,A[i] + i);
        }
        return maxnum;

    }
};
// @lc code=end

