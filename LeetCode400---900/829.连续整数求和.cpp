/*
 * @lc app=leetcode.cn id=829 lang=cpp
 *
 * [829] 连续整数求和
 */

// @lc code=start
class Solution {
public:
//读题，正整数
    int consecutiveNumbersSum(int N) {
        //第一遍想法  居然超时
        // if(N < 3)
        //     return 1;
        // int left = 1;
        // int right = 2;
        // int sum = 3;
        // int count = 0;
        // while(left < right)
        // {
        //     if(sum == N)
        //     {
        //         ++count;
        //         sum -= left;
        //         ++left;
        //     }
        //     if(sum < N)
        //     {
        //         ++right;
        //         sum += right;
        //     }
        //     if(sum > N)
        //     {
        //         sum -= left;
        //         ++left;
        //     }
        // }
        // return count + 1;

        //看了大家的题解，自己果然弱爆了
        //也是自己没有好好静下来分析思考，总想着刷更多的题
        int count = 0;
        for(int i = 1;N > 0;N-=i,++i)
        {
            count += (N % i == 0);//很赞
        }
        return count;
    }
};
// @lc code=end

