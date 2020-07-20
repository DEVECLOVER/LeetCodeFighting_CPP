/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        // int maxnum = INT_MIN;
        // int temp = 0;
        //总体思路没错  把有环转变为无环
        //但是在执行将有环变为无环考虑时，没有利用互补思想，关键就在于是计算的数组保持连续，而不是分开
        //在数学上的，补集，反面考虑都是这个思路啊，吸取教训啊！
        // if(A.back() < 0)
        // {
        //     for(int i = 0;i < A.size();++i)
        //     {
        //         temp = max(temp + A[i],A[i]);
        //         maxnum = max(maxnum,temp);
        //     }
        //     return maxnum;
        // }
        // else
        // {
        //     temp = A.back();
        //     maxnum = temp;
        //     for(int i = A.size() - 2;i >= 0;--i)
        //     {
        //         if(A[i] < 0)
        //         {
        //             for(int j = 0;j < i;++j)
        //             {
        //                 temp = max(temp + A[j],A[j]);
        //                 maxnum = max(maxnum,temp);
        //             }
        //             break;
        //         }
        //         else
        //         {
        //             temp += A[i];
        //             maxnum = temp;
        //         }
        //     }
        //     return maxnum;
        // }

        int maxnum = INT_MIN;
        int temp = 0;
        for(int i = 0;i < A.size();++i)
        {
            temp = max(temp + A[i],A[i]);
            maxnum = max(maxnum,temp);
        }
        int minnum = INT_MAX;
        int sum = 0;
        temp = 0;
        for(int i = 0;i < A.size();++i)
        {
            sum += A[i];
            temp = min(temp + A[i],A[i]);
            minnum = min(minnum,temp);
        }
        return maxnum  < (sum - minnum) && sum != minnum  ? sum - minnum : maxnum;

    }
};
// @lc code=end

