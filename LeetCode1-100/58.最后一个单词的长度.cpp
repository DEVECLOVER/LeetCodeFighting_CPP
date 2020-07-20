/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
//一次过  第一想法 这个题目的考点是什么呢？最直接的做法
// [AC]  
    int WordLen(string s)
    {
        int count = 0;
        int len = s.size();
        for(int i = len - 1;i >= 0;--i)
        {
            if(s[i] == ' ')
            {
                if(count < 1)
                    continue;
                else
                {
                    return count;
                }
            }
            else
            {
                ++count;
            }
        }
        return count;

    }
    int lengthOfLastWord(string s) {
        return WordLen(s);
    }
};
// @lc code=end

