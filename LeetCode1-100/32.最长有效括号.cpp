/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
//自己第一次想法的代码，so ugly
    int UglyCode(string s)
    {
        int maxlen = 0;
        stack<char> con;
        for(int i = 0;i < s.size();++i)
        {
            if(s[i] == ')' && (!con.empty()))
            {
                if(con.top() == '(')
                {
                    temp += 2;
                    con.pop();
                    maxlen = max(maxlen,temp);
                    continue;
                }
                else
                {
                    temp = 0;
                }
            }
            con.push(s[i]);
            maxlen = max(maxlen,temp);
        }
        return maxlen;
    }
    int longestValidParentheses(string s) {
        //动态规划【AC】
        //这么定义可能是第一直觉，但只是生搬硬套而已吧。
        //如果对于状态转移方程有个思路，上面的定义只是硬套的
        // int maxans = 0;
        // vector<int> dp(s.size(),0);
        // //定义dp数组  
        // //状态转移函数呢？
        // //可以进一步优化控件复杂度
        // for (int i = 1; i < s.size(); i++) {
        //     //只需要考虑两个基本情况即可  
        //     if (s[i] == ')') 
        //     {
        //         if (s[i - 1] == '(') 
        //             dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
        //         else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') 
        //         {
        //             //基本形状 () (())  
        //             //关键一点 下标不要弄错
        //             dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
        //         }
        //         maxans = max(maxans, dp[i]);
        //     }
        // }
        // return maxans;

        //方法二 利用双指针  妙不可言  如何将两个for循环融合为一个呢？尝试后没成功，要考虑的情况很多
        //观察的很到位 
        // int left = 0;
        // int right = 0;
        // int maxlen = 0;
        // for(int i = 0;i < s.size();++i)
        // {
        //     if(s[i] == '(')
        //     {
        //         ++left;
        //     }
        //     else
        //     {
        //         ++right;
        //     }
        //     if(left == right)
        //     {
        //         maxlen = max(maxlen,2 * right);
        //     }
        //     else if(right > left)
        //     {
        //         left = 0;
        //         right = 0;
        //     }
        // }
        // left = 0;
        // right = 0;
        // for(int i = s.size() - 1;i >= 0;--i)
        // {
        //     if(s[i] == ')')
        //     {
        //         ++left;
        //     }
        //     else
        //     {
        //         ++right;
        //     }
        //     if(left == right)
        //     {
        //         maxlen = max(maxlen,2 * right);
        //     }
        //     else if(right > left)
        //     {
        //         left = 0;
        //         right = 0;
        //     }
        // }
        // return maxlen;
        //方法一 利用栈
        //这里栈的使用，可以联系到最大柱形矩形的面积
        //联系单调栈
        int maxlen = 0;
        stack<int> con;
        con.push(-1);
        int size = s.size();
        if(size < 2)
        {
            return 0;
        }
        int index = 0;
        //非常巧妙 存储位置 而不是字符
        //总结什么情况下存储index，当要求的结果与下标相关联时
        for(int i = 0;i < size;++i)
        {
            if(s[i] == '(')
            {
                con.push(i);
            }
            else
            {
                con.pop();
                if(con.empty())
                {
                    con.push(i);
                }
                else
                {
                    maxlen = max(maxlen,i - con.top());
                }
            }
        }
        return maxlen;
    }
};
// @lc code=end

