/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
class Solution {
public:
//brute method
// 事实证明，这种方法超时  8257/8266 
    int Brute(int m,int n)
    {
        if(m == 0)
            return 0;
        int sum = m;
        for(int i = m + 1;i <= n;++i)
            sum &= i;
        return sum;
    }
//math formula  如何分析推导呢，第一想法应该会有公式的，考察相邻的元素
//原本还想着查找相邻相与的公式，然后得到递推的，结果看了题解，还有更妙精妙的
//因为一旦某一位出现了0，就都为零了，只需要找到最高位相等的，很妙。
    int Cool(int m,int n)
    {
        int count = 0;
        while(m != n)
        {
            m >>= 1;
            n >>= 1;
            ++count;
        }
        return m << count;
    }

    int rangeBitwiseAnd(int m, int n) {
        //return Brute(m,n);
        return Cool(m,n);
    }
};
// @lc code=end

