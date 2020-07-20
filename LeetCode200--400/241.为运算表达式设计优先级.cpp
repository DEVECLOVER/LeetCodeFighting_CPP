/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
//非常好 暴力递归
//进一步优化 加备忘录
//动态规划   
    bool IsOperator(char ch)
    {
        return ch == '-' || ch == '+' || ch == '*';
    }
    int Calculate(int p,int q,char ch)
    {
        switch(ch)
        {
            case '-':
                return p - q;
            case '+': 
                return p + q;
            case '*':
                return p * q;
            default:
                return 0;
        }
    }
    vector<int> diffWaysToCompute(string input) {
        if(input.empty())
            return vector<int>();
        vector<int> res;
        int num = 0;
        int index = 0;
        while(index < input.size() && !IsOperator(input[index]))
        {
            num = (num << 3) + (num << 1) + (input[index] & 0xf);
            ++index;
        }
        if(index == input.size())
        {
            res.push_back(num);
            return res;
        }
        for(int i = 0;i < input.size();++i)
        {
            if(IsOperator(input[i]))
            {
                vector<int> p = diffWaysToCompute(input.substr(0,i));
                vector<int> q = diffWaysToCompute(input.substr(i + 1));
                for(auto pnum : p)
                {
                    for(auto qnum : q)
                    {
                        res.push_back(Calculate(pnum,qnum,input[i]));
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

