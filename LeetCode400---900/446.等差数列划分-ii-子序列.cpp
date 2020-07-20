/*
 * @lc app=leetcode.cn id=446 lang=cpp
 *
 * [446] 等差数列划分 II - 子序列
 */

// @lc code=start
#define LL long long
class Solution {
public:
//DFS  判断所有的子序列   数字溢出问题  
// 超时 【NAC】
    void DFS(vector<int>& A,int index,int& count,vector<int> res)//这里vector不能使用引用
    {
        if(index >= A.size())
        {
            if(res.size() > 2)
            {
                int len = res.size();
                // for(int i = 1;i < len - 1;++i)
                // {
                //     if(res[i + 1] < INT_MIN + res[i] || res[i] < INT_MIN + res[i - 1] 
                //         || res[i + 1] - res[i] > INT_MAX  || res[i] - res[i - 1] > INT_MAX  || res[i + 1] - res[i] != res[i] - res[i - 1])
                //         return;
                // }
                for(int i = 1;i < len - 1;++i)
                {
                    if((LL)res[i + 1] - (LL)res[i] != (LL)res[i] - (LL)res[i - 1])
                        return;
                }
                ++count;
            }
            return;
        }
        DFS(A,index + 1,count,res);
        res.push_back(A[index]);
        DFS(A,index + 1,count,res);
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        int count = 0;
        vector<int> res;
        DFS(A,0,count,res);
        return count;
    }
};
// @lc code=end

