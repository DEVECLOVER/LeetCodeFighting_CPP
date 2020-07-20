/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
class Solution {
public:
//递归解决  DFS即可 第一想法
//主要明确三点：什么时候终止，在这里是等于最后一个元素就终止了，以前多半是等于len的时候，
//什么时候加入元素，也要明确  还有什么时候pop
//优化的考虑就是：剪枝的效率
    void PathCore(vector<vector<int>>& graph,vector<vector<int>>& res,vector<int>& temp,int index,const int& obj)
    {
        temp.push_back(index);
        if(index >= obj)
        {
            res.push_back(temp);
        }
        for(auto num : graph[index])
        {
            PathCore(graph,res,temp,num,obj);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> temp;
        int obj = graph.size();
        if(obj < 1)
            return res;
        PathCore(graph,res,temp,0,obj - 1);
        return res;
    }
};
// @lc code=end

