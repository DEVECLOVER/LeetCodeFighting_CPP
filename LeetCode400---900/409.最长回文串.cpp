/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
//字母出现的次数 偶数 奇数
    int longestPalindrome(string s) {
        map<char,int> hashmap;
        for(auto ch : s)
            ++hashmap[ch];
        int res = 0;
        for(auto ele : hashmap)
        {
            res += (ele.second & 1 ? 2 * (ele.second >> 1) : ele.second);
        }
        return res == s.size() ? res : res + 1;//如果res等于字符串长度，说明字符出现次数都是偶数
        //也有从反面考虑，减去出现奇数的个数
    }
};
// @lc code=end

