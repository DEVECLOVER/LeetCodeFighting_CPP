/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
 */

// @lc code=start
class Solution {
public:
//问题 ： 如何快速分割空格
    bool wordPattern(string pattern, string str) {
        int preindex = -1;
        vector<string> strarr;
        for(int i = 0;i < str.size();++i)
        {
            if(str[i] == ' ')
            {
                strarr.push_back(str.substr(preindex + 1,i - preindex - 1));
                preindex = i;
            }
        }
        strarr.push_back(str.substr(preindex + 1));
        if(strarr.size() != pattern.size())
            return false;
        map<char,int> pathash;
        map<string,int> strhash;
        for(int i = 0;i < strarr.size();++i)
        {
            if(pathash[pattern[i]] != strhash[strarr[i]])
                return false;
            else
            {
                if(pathash[pattern[i]] == 0)
                {
                    pathash[pattern[i]] = i + 1;
                    strhash[strarr[i]] = i + 1;
                }
            }
        }
        return true;

    }
};
// @lc code=end

