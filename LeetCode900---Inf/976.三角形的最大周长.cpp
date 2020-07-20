/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */

// @lc code=start
class Solution {
public:
//第一想法  【通过】
//还可以怎么改进呢？耗时在于排序，如何不排序呢？
//题解中有说的用堆来维护最大的三个值
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        int circle = 0;
        int len = A.size();
        for(int i = len - 3;i >= 0;--i)
        {
            if(A[i] + A[i + 1] > A[i + 2])
            {
                circle = A[i] + A[i + 1] + A[i + 2];
                return circle;
            }
        }
        return circle;
    }
};
// @lc code=end

