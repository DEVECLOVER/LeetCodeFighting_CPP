/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */

// @lc code=start
class Solution {
public:
//第一感觉，联系滑动窗口最大值，
//也容易联想到动态规划和贪心
//但是如何确定状态转移方程和贪心策略呢
//自己对于动态规划的理解还是差点火候啊，不够深刻
//要不然这题没有什么想法的？
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int len = A.size();
        vector<int> dp(len + 1,0);
        for(int i = 1;i <= len;++i)
        {
            int tempmax = -1;
            for(int j = i - 1;j >= max(i - K,0);--j)
            {
                tempmax = max(tempmax,A[j]);
                dp[i] = max(dp[i],dp[j] + tempmax * (i - j));
            }
        }
        return dp[len];
    }
};
// @lc code=end

