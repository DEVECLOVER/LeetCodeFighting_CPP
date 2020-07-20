/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
//递归实现即可  或者利用栈  【AC】
    int Calculus(int num1,int num2,string str)
    {
        // switch (str) //怪不得，C++的switch不识别字符串
        // {
        //     case "+":
        //         return num1 + num2;
        //     case "-":
        //         return num1 - num2;
        //     case "*":
        //         return num1 * num2;
        //     case "/":
        //         return num1 / num2;
        //     default:
        //         break;
        // }
        // return 0;
        if(str == "+")
            return num1 + num2;
        else if(str == "-")
            return num1 - num2;
        else if(str == "*")
            return num1 * num2;
        else
            return num1 / num2;
    }
    int GMT(vector<string>& nums)
    {
        stack<int> mystack;
        for(auto num : nums)
        {
            if(num == "-" || num == "+"
                || num == "*" || num == "/")
            {
                int num2 = mystack.top();
                mystack.pop();
                int num1 = mystack.top();
                mystack.pop();
                mystack.push(Calculus(num1,num2,num));
            }
            else
            {
                mystack.push(stol(num));
            }
        }
        return mystack.top();
    }
    int evalRPN(vector<string>& tokens) {
        return GMT(tokens);
    }
};
// @lc code=end

