/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
//【AC】
    uint32_t GMT(uint32_t n)
    {
        uint32_t res = 0;
        uint32_t index = 1;
        for(int i = 0;i < 32;++i)
        {
            //第一遍写的时候，写成了下述,这样得出来的不是某一位的值，而是幂值，所以还要再还远回去，即加上右移
            //temp = (n & (index << i));  
            int temp = ((n & (index << i)) >> i); 
            res |= (temp << (31 - i));
        }
        return res;
    }
    uint32_t reverseBits(uint32_t n) {
        return GMT(n);
    }
};
// @lc code=end

