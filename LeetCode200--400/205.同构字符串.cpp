/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,int> shash;
        map<char,int> thash;
        for(int i = 0;i < s.size();++i)
        {
            if(shash[s[i]] != thash[t[i]])
                return false;
            else
            {
                if(shash[s[i]] == 0)
                {
                    shash[s[i]] = i + 1;  //之所以不设为i，因为 i = 0时，与map的初始化一样 比如 aa ab
                    thash[t[i]] = i + 1;
                }
            }
        }
        return true;

    }
};
// @lc code=end

