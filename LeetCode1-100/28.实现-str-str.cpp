/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
//这是最直觉的做法，但是重复性高。
//子问题之间是否有联系呢？看了题解果然有不少快速查找的算法，如何快速的偏移，而不是一步步的移动。
//[AC]
    int Violent(string str,string obj)
    {
        if(obj == "")
            return 0;
        int len = str.size();
        int objlen = obj.size();
        //注意i 的最后取值，之前一直报错
        for(int i = 0;i <= len - objlen;++i)
        {
            if(str.substr(i,objlen) == obj)
                return i;
        }
        return -1;
    }
// KMP，BM，Horspool  Sunday 算法
    int strStr(string haystack, string needle) {
        return Violent(haystack,needle);
    }
};
// @lc code=end

