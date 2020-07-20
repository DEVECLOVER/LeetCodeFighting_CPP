/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution {
public:
//常规的hash
//滑动窗口的妙用 
    vector<string> findRepeatedDnaSequences(string s) {
        const int len = 10;
        map<string,int> hashmap;
        vector<string> res;
        if(s.size() <= len)
            return res;
        for(int i = 0;i < s.size() - len + 1;++i)
        {
            string str = s.substr(i,len);
            ++hashmap[str];
        }
        for(auto str : hashmap)
        {
            if(str.second > 1)
                res.push_back(str.first);
        }
        return res;
    }
};
// @lc code=end

