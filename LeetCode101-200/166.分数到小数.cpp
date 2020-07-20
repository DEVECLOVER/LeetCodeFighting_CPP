/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */

// @lc code=start
class Solution {
public:
//耗时一个小时，终于解决了，太不容易了
//从有了想法，很快写出了自己的框架，但是，一提交都是问题
//数字溢出没有考虑，
    string GMT(int num,int denom)
    {
        if(num == 0)
            return "0";
        string sign = double(num) / denom < 0 ? "-" : "";
        long long numll = abs(num);
        long long denomll = abs(denom);
        long long integer = numll / denomll;
        if(numll % denomll == 0)
            return sign + to_string(integer);
        string res = to_string(integer) + '.';
        map<pair<int,int>,int> hashmap;
        numll = numll % denomll;
        integer = 0;
        string loop = "";
        int count = -1;
        while (true)
        {   
            int quotient = 10 * numll / denomll;
            int remainder = 10 * numll % denomll;
            if(hashmap.count({quotient,remainder})) // 判断存在和下面的操作顺序考虑清楚
            {
                count = hashmap[{quotient,remainder}];
                break;
            }
            loop += to_string(quotient);
            if(remainder == 0)
                break;
            hashmap[{quotient,remainder}] = integer++;
            numll = remainder;
        }
        //当时第一想法还是通过这种方式找到循环位置呢？
        // for(auto ele : hashmap)
        // {
        //     if(ele.second < num)
        //         loop += ele.first.first + '0';
        //     else if(ele.second == num)
        //         loop += ('(' + to_string(ele.first.first));
        //     else
        //     {
        //         loop += to_string(ele.first.first);
        //     }
        // }
        // loop += ')';
        if(count != -1)
            loop = loop.substr(0,count) + '(' + loop.substr(count) + ')';
        return sign + res + loop;
        
    }
    string fractionToDecimal(int numerator, int denominator) {
        return GMT(numerator,denominator);
    }
};
// @lc code=end

