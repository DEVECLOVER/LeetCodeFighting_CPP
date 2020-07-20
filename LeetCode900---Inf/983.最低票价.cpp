/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
class Solution {
public:
    int DPCore(vector<int>& days,vector<int>& costs)
    {
        int last = days.back();

        vector<int> dp(last+1, 0);

        int idx = 0;

        for (int i = 1; i <= last; i++) 
        {
            if (i == days[idx]) 
            {
                int cost = INT_MAX;
                int oneDayAgo = i-1;
                int sevenDaysAgo = i-7>0?i-7:0;
                int thirtyDaysAgo = i-30>0?i-30:0;

                cost = min(dp[oneDayAgo] + costs[0], cost);
                cost = min(dp[sevenDaysAgo] + costs[1], cost);
                cost = min(dp[thirtyDaysAgo] + costs[2], cost);

                dp[i] = cost;

                idx++;
            } 
            else 
            {
                dp[i] = dp[i-1];
            }
        }

        return dp[last];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        return DPCore(days,costs);
    }
};

/ @lc code=end

