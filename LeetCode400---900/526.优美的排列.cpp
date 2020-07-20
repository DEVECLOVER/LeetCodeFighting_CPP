/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution {
public:
    void BackCore(int n,int& count,int index,vector<bool>& flag)
    {
        if(index > n)
        {
            ++count;
            return ;
        }
        for(int i = 1;i <= n;++i)
        {
            if(flag[i] && (index % i == 0 || i % index == 0))
            {
                flag[i] = false;
                BackCore(n,count,index + 1,flag);
                flag[i] = true;
            }
        }
    }
    int countArrangement(int N) {
        vector<bool> flag(N + 1,true);
        int count = 0;
        BackCore(N,count,1,flag);
        return count;
    }
};
// @lc code=end

