/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string tempstr = "";
        string result = "";
        for(int i = 0;i < s.size();)
        {
            if(s[i] != ' ')
            {
                tempstr += s[i];
                ++i;
            }
            else if(s[i] == ' ' && tempstr != "")
            {
                result = ' ' +  tempstr + result;
                tempstr = "";
                while(s[++i] == ' ');
            }
            else
            {
                ++i;
            }
        }
        result = tempstr != "" ? tempstr + result : result;
        return result[0] == ' ' ? result.substr(1) : result; 
    }
};
// @lc code=end

