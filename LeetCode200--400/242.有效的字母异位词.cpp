/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
//本质来说，就是字母出现相等  
//既然是相等，必须用两个hashmap吗，只用一个呢？一个加，一个减即可
//可以将字符串排序，比较是否相等即可
//利用hash
    bool isAnagram(string s, string t) {
        //两个hash
        // if(s.size() != t.size())
        //     return false;
        // map<char,int> shash;
        // map<char,int> thash;
        // for(int i = 0;i < s.size();++i)
        // {
        //     ++shash[s[i]];
        //     ++thash[t[i]];
        // }
        // for(char ch = 'a';ch <= 'z';++ch)
        //     if(shash[ch] != thash[ch])
        //         return false;
        // return true;

        //一个hash
        // if(s.size() != t.size())
        //     return false;
        // map<char,int> hashmap;
        // for(int i = 0;i < s.size();++i)
        // {
        //     ++hashmap[s[i]];
        //     --hashmap[t[i]];
        // }
        // for(auto ele : hashmap)
        //     if(ele.second)
        //         return false;
        // return true;

        //直接将字符串排序即可
        if(s.size() != t.size())
            return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;


    }
};
// @lc code=end

