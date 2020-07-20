/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> con(n,true);
        for(int i = 2;i * i < n;++i)
        {
            if(con[i])
            {
                for(int j = i * i ;j < n;j += i)
                {
                    con[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2;i < n;++i)
            if(con[i])
                ++count;
        return count;
    }
};
// @lc code=end

