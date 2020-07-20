/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
// [AC]
// 
    double PowRecursion(double x,long long n)
    {
        if(n == 0)
            return 1;
        double res = PowRecursion(x,n >> 1);
        return n & 1 ? res * res * x : res * res;
    }
    double PowCore(double x,int n)
    {
        if(abs(x) < 1e-10)
            return 0.0;
        if(n == 0)
            return 1;
        int sign = n < 0 ? -1 : 1;
        long long num = (long long)abs(n);
        double res = PowRecursion(x,num);
        return sign < 0 ? 1.0 / res : res;
        
    }
    double myPow(double x, int n) {
        return PowCore(x,n);
    }
};
// @lc code=end

