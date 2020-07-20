/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n < 1)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }
        if(n == 2)
        {
            return 2;
        }
        int f[3] = {1,2};
        for(int i = 3;i<=n;++i)
        {
            f[2] = f[0] + f[1];
            f[0] = f[1];
            f[1] = f[2];
        }
        return f[2];
    }
};
// @lc code=end

