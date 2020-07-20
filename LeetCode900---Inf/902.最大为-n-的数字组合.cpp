/*
 * @lc app=leetcode.cn id=902 lang=cpp
 *
 * [902] 最大为 N 的数字组合
 */

// @lc code=start
class Solution {
public:
//回溯算法 超时 
    void BackCore(vector<string>& str,const int& N,int index,int& count)
    {
        if(index > N)
            return ;
        for(auto ch : str)
        {
            if(index > INT_MAX / 10)  //整形溢出
                break;
            int sum = 10 * index + stol(ch);
            if(sum <= N)
            {
                ++count;
                BackCore(str,N,sum,count);
            }
            else
                break;
        }
    }
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int count = 0;
        BackCore(D,N,0,count);
        return count;
    }
};
// @lc code=end

