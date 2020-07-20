/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
     void PermuteNums(int pairs,int fc,int mc,vector<string>& result,string gender)
    {
        if (fc == pairs && mc == pairs)
        {
            result.push_back(gender);
            return;
        }
        if (fc < pairs)
        {
            PermuteNums(pairs, fc + 1, mc,result, gender+"(");
        }
        if (mc < fc)
        {
            PermuteNums(pairs, fc, mc + 1, result, gender + ")");
        }
    }
//一次过 【AC】
    void DFS(vector<string>& res,string str,const int& n,int leftindex,int rightindex)
    {
        if(leftindex == rightindex && leftindex == n)
            res.push_back(str);
        if(leftindex < n)
            DFS(res,str + '(',n,leftindex + 1,rightindex);
        if(rightindex < leftindex)
            DFS(res,str + ')',n,leftindex,rightindex + 1);
    }
// 每个选项有两种选择，共有2*n个。可以用回溯法找到所有的可能，然后判断是不是有效的，即可。

    vector<string> generateParenthesis(int n) {
        // vector<string> result;
        // string gender = "(";
        // PermuteNums(n,1,0,result,gender);
        // return result;

        //DFS
        vector<string> res;
        DFS(res,"",n,0,0);
        return res;
    }
};
// @lc code=end

