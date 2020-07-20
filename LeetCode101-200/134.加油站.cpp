/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
public:
//似乎大家的第一想法都是挨个检查每一个加油站，直到所有
//为啥就没有注意到，总gas和总cost呢，这是不应该的
//看看题解，简直妙不可言,值得好好分析思考
    int Cool(vector<int>& gas,vector<int>& cost)
    {
        int len = gas.size();
        int total = 0;
        int diff = 0;
        int res = 0;
        for(int i = 0;i < len;++i)
        {
            total += (gas[i] - cost[i]);
            diff  += (gas[i] - cost[i]);
            if(diff < 0)
            {
                res = i + 1;
                diff = 0;
            }
        }
        return total >= 0 ? res : -1;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        return Cool(gas,cost);
    }
};
// @lc code=end

