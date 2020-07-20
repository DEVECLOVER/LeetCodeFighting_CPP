/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n,INT_MAX);
        dp[0] = 1;
        vector<int> counter(primes.size(),0);
        for(int i = 1;i < n;++i)
        {
            for(int j = 0;j < primes.size();++j)
                dp[i] = min(dp[i],dp[counter[j]] * primes[j]);
            for(int j = 0;j < primes.size();++j)
            {
                if(dp[i] == dp[counter[j]] * primes[j])
                    ++counter[j];//不能执行完一次就break
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

