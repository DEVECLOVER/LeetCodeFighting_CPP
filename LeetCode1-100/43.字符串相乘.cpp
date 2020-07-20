/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution {
public:
//方法是很妙的，如果是求两个大数相加呢，
//则是需要一次for循环即可
    string MulCore(string num1,string num2)
    {
         if (num1 == "0" || num2 == "0") return "0";

        int n1 = num1.size(), n2 = num2.size();
        vector<int> rec(n1 + n2, 0);
        string res = "";
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                rec[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for (int i = n1 + n2 - 1; i > 0; i--) {
            rec[i - 1] += rec[i] / 10;
            rec[i] %= 10;
        }
        int t = 0;
        while (rec[t] == 0) t++;
        for (int i = t; i < n1 + n2; i++) {
            res.push_back('0' + rec[i]);
        }
        return res;
    }
    string multiply(string num1, string num2) {
        return MulCore(num1,num2);
    }
};
// @lc code=end

