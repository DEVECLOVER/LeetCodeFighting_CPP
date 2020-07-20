/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
//剪绳子问题
//这里存在贪心策略 在这里尽量剪出数字3
//联系四个按键问题，那个题目是否也存在贪心策略呢？
    int integerBreak(int n) {
        vector<int> dp(n + 1,1);
        for(int i = 2;i <= n;++i)
        {
            for(int j = 1;j <= (i >> 1);++j)
                dp[i] = max(dp[i],max(j * (i - j),j * dp[i - j])); //原本想的是 还要比较 dp[j] * dp[i - j]
        }
        return dp[n];

    }
};
// @lc code=end

