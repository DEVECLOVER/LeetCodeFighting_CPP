/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
//[AC]
//之所以转换为字符串，因为这样方便比较一些，如果直接使用数字的话，还得要取余，整除等操作
    bool GMT(int n)
    {
        if(n < 0)
            return false;
        string num = to_string(n);
        int left = 0;
        int right = num.size() - 1;
        while(left <= right)
        {
            if(num[left] != num[right])
                return false;
            ++left;
            --right;
        }
        return true;

    }
    bool isPalindrome(int x) {
        return GMT(x);
    }
};
// @lc code=end

