/*
 * @lc app=leetcode.cn id=319 lang=cpp
 *
 * [319] 灯泡开关
 */

// @lc code=start
class Solution {
public:
    int bulbSwitch(int n) {
        //参见单遵老师的趣味数论  
        //剩下的只有完全平方数
        int count  = 0;
        for(int i = 1;i * i <= n;++i)
            ++count;
        return count;
    }
};
// @lc code=end

