/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
//分析一下  实为26进制数
//[AC]
    string GMT(int n)
    {
        string res = "";
        while(n)
        {
            --n;
            res = char('A' + (n % 26)) + res; //艰难啊，一直卡在这一步，必须要加char
            n /= 26;
        }
        return res;
    }
    string GMT2(int n)
    {
        string res = "";
        while(n)
        {
            --n;
            res += ('A' + n % 26); //这么写却是可以的
            n /= 26;
        }
        reverse(res.begin(),res.end()); //有人说翻转比上述拼接还快
        return res;
    }
    string convertToTitle(int n) {
        //return GMT(n);
        return GMT2(n);
    }   
};
// @lc code=end

