/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
//

    string Brute(string str)
    {
        string res = "";
        int num = 1;
        int len = str.size();
        for(int i = 0;i < len - 1;++i)
        {
            if(str[i] == str[i + 1])
                ++num;
            else
            {
                res += (num + '0');
                res += str[i];
                num = 1;
            }
        }
        res += (num + '0');
        res += '1';//经过分析可知，最后一个字符一定为'1'
        return res;
    }
//经过分析，存在重复的子问题，递归即可。只需要判断开头的情况
    string countAndSay(int n) {
        string res = "1";
        for(int i = 0;i < n - 1;++i)
        {
            res = Brute(res);
        }
        return res;
    }
};
// @lc code=end

