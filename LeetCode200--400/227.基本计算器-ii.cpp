/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    bool IsDigit(char ch)
    {
        if(ch >= '0' && ch <= '9')
            return true;
        return false;
    }
    int calculate(string s) {
        stack<int> operand;
        char sign = '+';
        int num = 0;
        int len = s.size();
        for(int i = 0;i < len;++i)
        {
            char ch = s[i];
            int pre = 0;
            // if(ch == ' ')  //加了这句话，导致字符串末端出现空格，出现了bug，很大的教训啊
            //     continue;
            if(IsDigit(ch))
                num = 10 * num + (ch - '0');
            if((!IsDigit(ch) && ch != ' ') || i == len - 1)
            {
                switch(sign)
                {
                    case '+':
                        operand.push(num);
                        break;
                    case '-':
                        operand.push(-num);
                        break;
                    case '*':
                        pre = operand.top();
                        operand.pop();
                        operand.push(pre * num);
                        break;
                    case '/':
                        pre = operand.top();
                        operand.pop();
                        operand.push(pre / num);
                        break;
                }
                sign = ch;
                num = 0;
            }
        }
        while(!operand.empty())
        {
            num += operand.top();
            operand.pop();
        }
        return num;
    }
};
// @lc code=end

