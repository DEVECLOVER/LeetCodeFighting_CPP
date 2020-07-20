/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution {
public:
//容易想到产生0的条件，就是出现2 和 5，而10 100 本身也都是5的倍数，关键在于数字中5的因数有几个
//自己想了一下，觉得可以，举了几个数字（6 ,10 ,25）都是可行的，写出了下面的代码
//没想到一次过，因为基于之前的经历，自己都会考虑的不全面，缺胳膊少腿的。
//【AC】
    int GMT(int n)
    {
        int count = 0;
        while(n)
        {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
    int trailingZeroes(int n) {
        return GMT(n);
    }
};
// @lc code=end

