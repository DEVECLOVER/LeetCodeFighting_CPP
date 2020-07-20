/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    bool IsSym(string str)
    {
        int left = 0;
        int right = str.size() - 1;
        while(left < right)
        {
            if(str[left] != str[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
    void ParCore(string& str,int index,vector<string>& temp,vector<vector<string>>& result)
    {
        if(index >= str.size())
        {
            result.push_back(temp);
            return;
        }
        for(int i = index;i < str.size();++i)
        {
            int len = i - index + 1;
            if(!IsSym(str.substr(index,len)))
                continue;
            temp.push_back(str.substr(index,len));
            ParCore(str,i + 1,temp,result);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        if(!s.size())
            return result;
        ParCore(s,0,temp,result);
        return result;
    }
};
// @lc code=end

