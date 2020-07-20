/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
//求出总和，如果为奇数，false
//为偶数，维持一个集合A,从数组总不断选数，如果可以选到总和的一半，就为true，遍历整个数组没有的话，为false
    bool UglyCode(vector<int>& nums)
    {
        int sum = 0;
        for(auto num : nums)
            sum += num;
        if(sum & 1)
            return false;
        sum >>= 1;
        int halfsum = 0;
        sort(nums.begin(),nums.end());
        for(auto num : nums)
        {
            if(halfsum < sum)  //第一想法居然是挨个减，哎，想啥呢？老老实实的分析问题
                halfsum += num;
            else if(halfsum == sum)
                return true;
            else 
                return false;
            
        }
        return false;
    }
//不要看到别人说，你的头脑里能压入几个栈，那是达到一定高度的
//你要做的就是不断的写程序，头脑里要有程序  
//[NAC]  超时
    bool BackCore(vector<int>& nums,const int& halfsum,int temp,int index)
    {
        //这里在开头并没有放置判断条件，而是将判断条件放在了for循环里面
        //
        for(int i = index;i < nums.size();++i)
        {
            temp += nums[i];
            if(temp > halfsum)
            {
                temp -= halfsum;
                break;
            }
            if(temp == halfsum)
                return true;
            //之前写为了下述，是错误的
            // BackCore(nums,halfsum,temp,i + 1);
            //这就是之前自己一直是要总结的，什么时候结果作为判断条件
            if(BackCore(nums,halfsum,temp,i + 1))
                return true;
            temp -= nums[i];
        }
        return false;
    }
    //【AC】  这也可以作为从前向后不成功，从后向前便成功的一个例子
    bool NewBackCore(vector<int>& nums,int halfsum,int index)
    {
        if(halfsum == 0)  //判断条件放到开头 【AC】
            return true;
        for(int i = index;i < nums.size();++i)
        {
            if(halfsum - nums[i] < 0) //加上这个break 剪枝更加迅速，之后无须再算
                break;
            //可以将下述判断加到开头
            // if(halfsum - nums[i] == 0)
            //     return true;
            //之前写为了下述，是错误的
            // BackCore(nums,halfsum,temp,i + 1);
            //这就是之前自己一直是要总结的，什么时候结果作为判断条件
            halfsum -= nums[i];
            if(NewBackCore(nums,halfsum,i + 1))
                return true;
            halfsum += nums[i];
        }
        return false;
    }
//选或者不选  这么写的思路就非常清晰  正经的DFS
//从大到小排序 【AC】  
//数组从小到大排序 【NAC】  暴力超时  递归级数太多了
    bool DFS(vector<int>& nums,int halfsum,int index)
    {
        if(index >= nums.size() || halfsum < 0)
            return false;
        if(halfsum == 0)
            return true;
        return DFS(nums,halfsum - nums[index],index + 1) || DFS(nums,halfsum,index + 1);
    }
//思想是借鉴0 1 背包问题
//状态的定义  状态转移方程
    bool DpCore(vector<int>& nums,int halfsum)
    {
        int len = nums.size();
        vector<vector<bool>> dp(len + 1,vector<bool>(halfsum + 1,false));
        for(int i = 0;i <= len;++i)
            dp[i][0] = true;  //这里的含义也要明确
        for(int i = 1;i <= len;++i)
        {
            for(int j = 1;j <= halfsum;++j)
            {
                if(j < nums[i - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];//选 和 不选 （注意不选的公式）
            }
        }
        return dp[len][halfsum];
    }
    bool canPartition(vector<int>& nums) {
    //DFS 超时 【NAC】
        int sum = 0;
        for(auto num : nums)
            sum += num;
        if(sum & 1)
            return false;
        sum >>= 1;
        sort(nums.rbegin(),nums.rend()); //将数组从大到小排列
        //提前剪枝
        if(nums[0] > sum)
            return false;
        if(nums[0] == sum)
            return true;
        //return DFS(nums,sum,0);
        //return BackCore(nums,sum,0,0);
        //return NewBackCore(nums,sum,0);
        return DpCore(nums,sum);
    
    }
};
// @lc code=end

