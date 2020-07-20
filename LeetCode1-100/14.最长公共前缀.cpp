/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
//二分法即可   没想到提接中没人提到这种解法
//[AC]
    string Gca(string str1,string str2)
    {
        if(str1 == "" || str2 == "")
            return "";
        if(str1 == str2)
            return str1;
        int index = 0;
        while(str1[index] == str2[index])
            ++index;
        return str1.substr(0,index);
    }
    string Binary(vector<string>& strs,int start,int end)
    {
        if(start >= end)
            return strs[start];
        int mid = start + ((end - start) >> 1);
        string left = Binary(strs,start,mid);
        string right = Binary(strs,mid + 1,end);
        return Gca(left,right);
    }
// 就像一组数的最大公约数，能不能仿造最大前缀树，构造质因子树。用来求最大公约数。
// 还可以利用前缀树：但是自己并没有很简洁的思路。

    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len < 1)
            return "";
        return Binary(strs,0,len - 1);
    }
};
// @lc code=end

