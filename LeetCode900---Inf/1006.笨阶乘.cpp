/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] 笨阶乘
 */

// @lc code=start
class Solution {
public:
//总结一下，可以写个题解了，比他们都好
    int clumsy(int N) {
        int dp[] = {1,2,6,7};
        if(N < 5)
            return dp[N - 1];
        int count = N / 4;
        int reminder = N % 4;
        int res = 2 * N - 2 - 4 * (count - 1);
        return reminder == 0 ? res - 1 : res - dp[reminder - 1];
    }
};
// @lc code=end

