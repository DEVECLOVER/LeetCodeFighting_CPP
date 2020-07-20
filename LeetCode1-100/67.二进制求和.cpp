/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
// 【AC】  只是为了测试自己的想法，这种方法还是比较麻烦的
    string GMT(string a,string b)
    {
        if(b.size() > a.size())
            swap(a,b);
        int lenb = b.size();
        int lena = a.size();
        string res = "";
        while (lenb)
        {
            int temp = (a[lena - 1] - '0') + (b[lenb - 1] - '0');
            //res = (temp + '0') + res;
            res = to_string(temp) + res;
            --lenb;
            --lena;
        }
        while(lena)
        {
            res = to_string((a[lena - 1] - '0')) + res;
            --lena;
        }
        int carry = 0;
        lena = res.size();
        for(int i = lena - 1;i>= 0;--i)
        {
            int temp = (res[i] - '0') + carry;
            res[i] = (temp % 2 + '0');
            carry = temp / 2;
        }
        if(carry)
            res = '1' + res;
        return res;
    }
//同时还想到的是，使位数相同，前面补零即可  
// 【AC】
    string GMT2(string a,string b)
    {
        int lena = a.size();
        int lenb = b.size();
        while (lena < lenb)
        {
            a = '0' + a;
            ++lena;
        }
        while(lenb < lena)
        {
            b = '0' + b;
            ++lenb;
        }
        int carry = 0;
        for(int i = lena - 1;i >= 0;--i)
        {
            int temp = carry + (a[i] - '0') + (b[i] - '0');
            a[i] = temp % 2 + '0';
            carry = temp / 2;
        }
        if(carry)
            a = '1' + a;
        return a;
    }
    string addBinary(string a, string b) {
        //return GMT(a,b);
        return GMT2(a,b);
    }
};
// @lc code=end

