/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 *
 * [1306] 跳跃游戏 III
 */

// @lc code=start
class Solution {
public:
//计算机思维，我的想法依然不是计算机思维，还是人类思维
//我的想法是，逆向分析的，查找能够到达元素0的位置，问题变转换为能够到达该位置，
//继而继续以该位置为目标重复上述分析过程。但是如何变为代码呢？不好办。
//看了题解，看到了DFS，自己怎么没有想到呢，这题不还是两种选择的问题吗。
// 一次过  【AC】  关于函数参数放置问题：变动不大的参数尽量放到后面
    bool DFS(vector<int>& arr,int index,vector<bool>& flag,const int len)
    {
        if(arr[index] == 0)
            return true;
        flag[index] = true;
        int left = index - arr[index];
        if(left >= 0 && !flag[left] && DFS(arr,left,flag,len))
            return true;
        int right = index + arr[index];
        if(right < len && !flag[right] && DFS(arr,right,flag,len))
            return true;
        return false;
    }
    bool ReachCore(vector<int>& arr,int start)
    {
        int len = arr.size();
        vector<bool> flag(len,false);
        return DFS(arr,start,flag,len);
    }

//同样的思路，用BFS实现也是可以的  [AC]
    bool BFS(vector<int>& arr,int index)
    {
        map<int,bool> hashmap;
        queue<int> myqueue;
        myqueue.push(index);
        int len = arr.size();
        while(!myqueue.empty())
        {
            int mid = myqueue.front();
            myqueue.pop();
            int left = mid - arr[mid];
            if(left >= 0 && !hashmap.count(left))
            {
                if(arr[left] == 0)
                    return true;
                hashmap[left] = true;
                myqueue.push(left);
            }
            int right = mid + arr[mid];
            if(right < len && !hashmap.count(right))
            {
                if(arr[right] == 0)
                    return true;
                hashmap[right] = true;
                myqueue.push(right);
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        //return ReachCore(arr,start);
        return BFS(arr,start);
    }
};
// @lc code=end

