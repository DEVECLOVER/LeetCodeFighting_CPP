/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int GMT(string str)
    {
        int len = str.size();
        int index = 0;
        while(index < len && str[index] == ' ') // 开头判断空格
            ++index;
        if(index >= len)
            return 0;
        bool sign = true;
        if(str[index] == '-' || str[index] == '+') // 判断正负号
        {
            if(str[index] == '-')
                sign = false;
            ++index;
        }
        int res = 0; // 字母直接包含在里面
        while(index < len && (str[index] >= '0' && str[index] <= '9'))
        {
            int bit = str[index] - '0';
            if(res > (INT_MAX - bit)/10)   // 还是一样的判断溢出的方式
                return sign ? INT_MAX : INT_MIN;
            res = 10 * res + bit;
            ++index;
        }
        return sign ? res : -res;
    }
    int UglyCode(string str)
    {
        //如果采用把所有逻辑放到一个循环中，那么逻辑判断将是很繁杂的，极容易出错
        //所以，这就要具体问题具体分析，那么符号的操作都是在开头操作的
        //通过这个案例，也就清楚了这个分析套路  
        //方法一
        int sign = 0;
        int res = 0;
        bool flag = false;
        for(auto ch : str)
        {
            if(ch ==' ')
            {
                if(sign == 0 && !flag)
                    continue;
                else
                    return sign >= 0 ? res : sign * res;
            }
            if(ch >= '0' && ch <= '9')
            {
                int bit = ch - '0';
                if(res > (INT_MAX - bit)/10)
                    return sign >= 0? INT_MAX : INT_MIN;
                res = 10 * res + bit;
                flag = true;
            }
            else if((ch == '-' || ch == '+') && !flag)
            {
                if(res == 0)
                    sign = (ch == '-' ? -1 : 1);
                else
                    return 0;
                flag = true;
            }
            else
                return sign >= 0 ? res : sign * res;
        }
        return sign >= 0 ? res : sign * res;
    }
    int myAtoi(string str) {
        //return GMT(str);
        return UglyCode(str);
    }
};
// @lc code=end

