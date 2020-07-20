/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 */

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort(A.begin(),A.end());
        int count = 0;
        for(int i = 1;i < A.size();++i)
        {
            if(A[i] <= A[i - 1])
            {
                //注意顺序问题
                count += (abs(A[i] - A[i - 1])  + 1);
                A[i] += (abs(A[i] - A[i - 1])  + 1);
            }
        }
        return count;

    }
};
// @lc code=end

