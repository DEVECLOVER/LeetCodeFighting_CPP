/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
//两个联合起来，只有一个元素出现一次,没有想到异或法
    char findTheDifference(string s, string t) {
        // map<char,int> hashmap;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // for(int i = 0;i < s.size();++i)
        // {
        //     ++hashmap[s[i]];
        //     --hashmap[t[i]];
        //     if(hashmap[t[i]] < 0)
        //         return t[i];
        // }
        // return t[t.size() - 1];
        // for(auto ch : t)
        // {
        //     if(hashmap[ch] == 0)
        //         return ch;
        //     else
        //         --hashmap[ch];
        // }

        //异或
        // int res = 0;
        // for(auto ch : s)
        //     res ^= ch;
        // for(auto ch : t)
        //     res ^= ch;
        // return res;

        //差值
        int res = 0;
        for(int i = 0;i < s.size();++i)
        {
            res -= s[i];
            res += t[i];
        }
        return res + t[t.size() - 1];
    }
};
// @lc code=end

