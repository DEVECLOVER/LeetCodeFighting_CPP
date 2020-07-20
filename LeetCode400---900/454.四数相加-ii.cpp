/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int count = 0;
        int len = A.size();
        map<int,int> hashmap;
        for(int i = 0;i < len;++i)
        {
            for(int j = 0;j < len;++j)
            {
                ++hashmap[(A[i] + B[j])];
            }
        }
        for(int i = 0;i < len;++i)
        {
            for(int j = 0;j < len;++j)
            {
                if(hashmap[-(C[i] + D[j])])
                   count += hashmap[-(C[i] + D[j])];
            }
        }
        return count;
    }
};
// @lc code=end

