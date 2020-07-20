/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
// 重点：掌握数字溢出的判断
//[AC]
    int Core(int x)
    {
       int sign = 1;
       if(x == INT_MIN || x == INT_MAX)
            return 0;
       if(x < 0)
       {
            x = -x;
            sign = -1;
       }
       int num = 0;
       while(x)
       {
           int bit = x % 10;
           if(num > (INT_MAX - bit) / 10) // 即根据公式判断
                return 0;
            num = 10 * num + bit;
            x /= 10;
       }
       return sign == 1 ? num : -num;
    }
    int reverse(int x) {
        return Core(x);
    }
};
// @lc code=end

