/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int left = 0;
        int right = 0;
        int match = 0;
        map<char,int> hashmap;
        map<char,int> sourcemap;
        for(auto ch : p)
            ++hashmap[ch];
        while(right < s.size())
        {
            //这是在传统的滑动窗口上进行优化，因为一旦发现，不需要的字符便可以直接跳过去
            if(!hashmap.count(s[right]))
            {
                left = right + 1;
                match = 0;
                sourcemap.clear(); //之前一直没想到要释放，还是放到VS中调试才发现错误的
            }
            else
            {
                if(++sourcemap[s[right]] == hashmap[s[right]])
                    ++match;
                while(match == hashmap.size())
                {
                    if(right - left + 1 == p.size())
                        res.push_back(left);
                    if(hashmap.count(s[left]))
                    {
                        if(--sourcemap[s[left]] < hashmap[s[left]])
                            --match;
                    }
                     ++left;
                }
            }
            ++right;

        }
        return res;
    }
};
// @lc code=end

