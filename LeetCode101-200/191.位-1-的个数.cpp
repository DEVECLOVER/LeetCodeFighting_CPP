/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
//两种思路，一个是每次移动 n ,一个是移动哨兵
//【AC】
    int GMT1(uint32_t n)
    {
        uint32_t index = 1;
        int count = 0;
        while(index)
        {
            if(n & index)
                ++count;
            index <<= 1;
        }
        return count;
    }
//[AC]
    int GMT2(uint32_t n)
    {
        int count = 0;
        //如果这里是有符号的话，便失效了，因为右移时，左边会补零，死循环了
        while(n)
        {
            if(n & 1)
                ++count;
            n >>= 1;
        }
        return count;
    }
    int hammingWeight(uint32_t n) {
        //return GMT1(n);
        return GMT2(n);
    }
};
// @lc code=end

