/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
//这里transform 无法使用
    bool IsValid(char ch)
    {
        if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z'))
            return true;
        return false;
    }
    bool GMT(string s)
    {
        if(s.empty())
            return true;
        //s = tolower(s);  //无法直接将字符串变为大小写
		//transform(s.begin(), s.end(), s.begin(), tolower);
        string res = "";
        for(auto ch : s)
        {
            if(IsValid(ch))
                res += ch;
        }
        int left = 0;
        int right = s.size() - 1;
        for(int i = left,j = right;i < j;)
        {
            if(res[i] != res[j])
                return false;
            else
            {
                ++i;
                --j;
            }
        }
        return true;
    }
//又学习了一个STL函数
// 【AC】
    bool GMT2(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        for(int i = left,j = right;i < j;)
        {
            while(!isalnum(s[i]) && i < j)
                ++i;
            while(!isalnum(s[j]) && i < j)
                --j;
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            else
            {
                ++i;
                --j;
            }
        }
        return true;
    }

    bool isPalindrome(string s) {
        //return GMT(s);
        return GMT2(s);
    }
};
// @lc code=end

