/*
 * @lc app=leetcode.cn id=500 lang=cpp
 *
 * [500] 键盘行
 */

// @lc code=start
class Solution {
public:
//哈希表
//前缀树  对于长度较长的字符串还得分批匹配
//预处理阶段 还得排序，当前的单词也得排序 
    vector<string> findWords(vector<string>& words) {
        string s0 = "qwertyuiop";
        string s1 = "asdfghjkl";
        string s2 = "zxcvbnm";
        map<char,int> hashmap;
        vector<string> res;
        for(auto ch : s0)
        {
            hashmap[ch] = 1;
            hashmap[ch - 32] = 1;
        }
        for(auto ch : s1)
        {
            hashmap[ch] = 2;
            hashmap[ch - 32] = 2;
        }
        for(auto ch : s2)
        {
            hashmap[ch] = 3;
            hashmap[ch - 32] = 3;
        }
        for(auto word : words)
        {
            int len = 0;
            for(auto w : word)
                len += hashmap[w];
            if(len == hashmap[word[0]] * word.size())
                res.push_back(word);
        }
        return res;

    }
};
// @lc code=end

