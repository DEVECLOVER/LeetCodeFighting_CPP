/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */

// @lc code=start
class Solution {
public:
//如何定义dp数组
//我的第一想法是，dp[i]表示i位数字的个数，但是递推公式很难
//实际上呢，每增加一位，只需要计算 i+1的不重复数字个数就好了
//因为dp[i]的个数已经计算好了  
//所以这是不同的定义问题
    int countNumbersWithUniqueDigits(int n) {
        if(n  == 0)
            return 1;
        else if(n == 1)
            return 10;
        else if(n == 2)
            return 91;
        else
        {
            long long ans = 81;
            long long count = 91;
            for(int i = 3;i <= n && i < 11;++i)
            {
                ans = ans * (11 - i);
                count += ans;
            }
            return count;
        }
    }
};
// @lc code=end

