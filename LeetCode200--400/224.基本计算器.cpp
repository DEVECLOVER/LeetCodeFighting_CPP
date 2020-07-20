/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */

// @lc code=start
class Solution {
public:
    bool IsChar(char ch)
    {
        if(ch == '(' || ch == '+' || ch == '-')
            return true;
        return false;
    }
    int Calc(int num1,int num2,char ch)
    {
        switch(ch)
        {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
        }
        return 0;
    }
    int calculate(string s) {
        stack<int> st;
        int res = 0, n = s.size(), sign = 1;//自己在想时，没有想到标志位，导致计算时很不方便
        for(int i=0; i<n; i++) {
            int num = 0;
            if(s[i] >= '0') 
            {
                while(i<n && s[i] >= '0') 
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                res += sign * num;
            }
            else if(s[i] == '+') sign = 1;
            else if(s[i] == '-') sign = -1;
            else if(s[i] == '(') {
                st.push(res);
                st.push(sign); //想到存储符号位也是不容易的
                res = 0;
                sign = 1;
            }
            else if(s[i] == ')') {
                res *= st.top(); st.pop();
                res += st.top(); st.pop();
            }
        }
        return res;
    }
};
// @lc code=end

