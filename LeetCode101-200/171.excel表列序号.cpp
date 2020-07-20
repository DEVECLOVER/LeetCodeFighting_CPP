/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution {
public:
    int GMT(string s)
    {
        int index = 0;
        int sum = 0;
        while(s[index] != '\0')
        {
            sum = 26 * sum + (s[index] - 'A') + 1;
            ++index;
        }
        return sum;
    }
    int titleToNumber(string s) {
        return GMT(s);
    }
};
// @lc code=end

