/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
//也联系到了快慢指针
    int Next(int n)
    {
        int res = 0;
        while(n)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = Next(n);
        while(slow != fast)
        {
            slow = Next(slow);
            fast = Next(Next(fast));
        }
        return slow == 1;

    }
};
// @lc code=end

