/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

// @lc code=start
class Solution {
public:
// 第一想法，但是不正确的。
//[NAC]
    string GMT(string dominoes)
    {
        dominoes = "." + dominoes + ".";
        string str1 = dominoes;
        string str2 = dominoes;
        int len = dominoes.size();
        for(int i = 1;i < len - 1;++i)
        {
            if(str1[i] == '.')
            {
                if(str1[i - 1] == 'R' && str1[i + 1] != 'L')
                    str1[i] = 'R';
                else if(str1[i - 1] != 'R' && str1[i + 1] == 'L')
                    str1[i] = 'L';
            }
        }
        str1 =  str1.substr(1,len - 2);
        for(int i = len - 2;i >= 1;--i)
        {
            if(str2[i] == '.')
            {
                if(str2[i - 1] == 'R' && str2[i + 1] != 'L')
                    str2[i] = 'R';
                else if(str2[i - 1] != 'R' && str2[i + 1] == 'L')
                    str2[i] = 'L';
            }
        }
        str2 =  str2.substr(1,len - 2);
        for(int i = 0;i < len - 2;++i)
        {
            if(str2[i] == '.')
            {
                continue;
            }
            else if(str1[i] == '.')
            {
                str1[i] = str2[i];
            }
            else if(str2[i] != str1[i])
            {
                str1[i] = '.';
            }
        }
        return str1;
    }
    string pushDominoes(string dominoes) 
    {
        return GMT(dominoes);
    }
};
// @lc code=end

