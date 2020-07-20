/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    //如果不使用引用  超出内存
    bool DFS(int index,vector<vector<int>>& dp,vector<int>& flag)
    {
        if(flag[index] == 1)
            return false;
        if(flag[index] == -1)
            return true;
        flag[index] = 1;
        for(auto ele : dp[index])
        {
            if(!DFS(ele,dp,flag))
                return false;
        }
        flag[index] = -1;
        return true;
    }
    bool DFSDone(int numCourses, vector<vector<int>>& prerequisites)
    {
        if(numCourses < 1 || prerequisites.empty())
            return true;
        vector<vector<int>> dp(numCourses,vector<int>());
        vector<int> flag(numCourses,0);
        for(auto ele : prerequisites)
        {
            dp[ele[1]].push_back(ele[0]);
        }
        for(int i = 0;i < numCourses;++i)
        {
            if(!DFS(i,dp,flag))
                return false;
        }
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//BFS 拓扑排序  通过入度来计算
//DFS 计算是否存在环  精妙的很
        //return DFSDone(numCourses,prerequisites);

//通过入度来计算 思路是很清晰的
        vector<int> inDegrees(numCourses,0);
        vector<vector<int>> dp(numCourses,vector<int>());
        for(auto ele : prerequisites)
        {
            ++inDegrees[ele[0]];//第一个元素为被指向的，第二个是出发点   [1,0]  即 0->1
            dp[ele[1]].push_back(ele[0]);
        }
        queue<int> myqueue;
        for(int i = 0 ;i < numCourses;++i)
        {
            if(inDegrees[i] == 0)
                myqueue.push(i);
        }
        while(!myqueue.empty())
        {
            int cur = myqueue.front();
            myqueue.pop();
            --numCourses;
            for(auto ele : dp[cur])
            {
                if(--inDegrees[ele] == 0)
                    myqueue.push(ele);
            }
        }
        return numCourses == 0;


    }
};
// @lc code=end

