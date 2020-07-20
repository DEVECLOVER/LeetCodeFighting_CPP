/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 */

// @lc code=start
class Solution {
public:
//先按照到A地的价值，从小到大排序，如果相同，在按照到B的值
//贪心算法即可  没想到贪心策略错误了，吸取教训！
    int twoCitySchedCost(vector<vector<int>>& costs) {
        //第一遍想法
        // sort(costs.begin(),costs.end(),[](vector<int>& p,vector<int>& q)
        // {
        //     return p[0] != q[0] ? p[0] < q[0] : p[1] > q[1];
        // });
        //实际的贪心策略应该是每个人两地的费用差值大小的排序
        sort(costs.begin(),costs.end(),[](vector<int>& p,vector<int>& q)
        {
            return (p[0] - p[1]) < (q[0] - q[1]);
        });
        int len = costs.size();
        int halflen = (len >> 1);
        int cost = 0;
        //这两句可以浓缩成一句话
        // for(int i = 0;i < halflen;++i )
        //     cost += costs[i][0];
        // for(int i = halflen;i < len;++i)
        //     cost += costs[i][1];
        for(int i = 0;i < halflen;++i)
        {
            cost += (costs[i][0] + costs[i + halflen][1]);
        }

        return cost;
    }
};
// @lc code=end

