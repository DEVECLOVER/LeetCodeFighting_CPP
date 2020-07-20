/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
// 【AC】
// 压根没有心情看这段代码了。
    vector<vector<int>> UglyCode(vector<vector<int>>& intervals)
    {
        if (intervals.size() == 0 || intervals.size() == 1) return intervals;
        int u = 0, v = 0;
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        while (v < intervals.size()) 
        { 
            if (intervals[v][0] > intervals[u][1]) 
            {
                ans.emplace_back(intervals[u]);
                u = v;
            } else if (intervals[v][1] <= intervals[u][1]) 
            {
                ++ v;
            } else 
            {
                intervals[u][1] = intervals[v][1];
                ++ v;
            }
        }
        ans.emplace_back(intervals[u]);
        return ans;
    }
//【AC】
// 从插入区间来看这道题,一切都是那么显然了。我们关注点就是最后的back
    vector<vector<int>> GMT(vector<vector<int>>& nums)
    {
        if(nums.size() < 2)
            return nums;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end(),[](vector<int>& p,vector<int>& q)
        {
            return p[0] < q[0];
        });
        res.push_back(nums[0]);
        int len = nums.size();
        for(int i = 1;i < len;++i)
        {
            if(res.back()[1] < nums[i][0])
                res.push_back(nums[i]);
            else
            {
                //这里面没有更改 res.back()[0]的值，是因为前面已经排好序了
                res.back()[1] = max(res.back()[1],nums[i][1]);
            }
        }
        return res;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //return UglyCode(intervals);
        return GMT(intervals);
    }

};
// @lc code=end

