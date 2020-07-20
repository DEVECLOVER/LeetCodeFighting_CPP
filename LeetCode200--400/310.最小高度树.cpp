/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @lc code=start
class Solution {
public:
//DFS即可 对每个节点进行高度计算，小的加入vector
    void DFS(int index,int depth,vector<int>& height,vector<vector<int>>& dp,vector<bool>& flag)
    {
        flag[index] = true;
        for(auto num : dp[index])
        {
            if(flag[num])
                continue;
            DFS(num,depth + 1,height,dp,flag);
        }
        flag[index] = false;
        height[index] = depth; //有问题  
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n < 1 || edges.empty())
            return vector<int>();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(auto edge : edges)
        {
            dp[edge[0]].push_back(edge[1]);
            dp[edge[1]].push_back(edge[0]);
        }
    }
};
// @lc code=end

