/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution 
{
public:
//之所以额外考虑负数，是因为他和正数相加便可能产生0，这样便无穷多了
//该怎么限制呢？就要围绕产生0 的条件
//回溯算法即可，每次均有多种选择 
//暴力回溯 超时 【NAC】  这是自顶向下的思路  并没有借用之前的结果
    void BackCore(vector<int>& nums,const int& target,int value,int& res)
    {
        if(value == target)
        {
            ++res;
            return;
        }
        for(auto num : nums)
        {
            value += num;
            if(value > target)
                break;
            BackCore(nums,target,value,res);
            value -= num;
        }
    }
//暴力DFS 超时 【NAC】
    int DFS(vector<int>& nums,int target)
    {
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        unsigned int res = 0;
        for(auto num : nums)
            if(target >= num)
                res += DFS(nums,target - num);
        return res;
    }
//使用备忘录  [AC]
    int DFSMemo(vector<int>& nums,int target,map<int,int>& memo)
    {
        if(memo.count(target))
            return memo[target];
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        unsigned int res = 0;
        for(auto num : nums)
            if(target >= num)
                res += DFSMemo(nums,target - num,memo);
        memo[target] = res;
        return res;
    }
//动态规划 看到这个题目第一眼居然不是动态规划，还得多练习  [AC]
//编码格式
    int DpCore(vector<int>& nums,int target)
    {
        vector<unsigned int> dp(target + 1,0); // 这里使用 long long 不行，反而unsigned int 可以
        dp[0] = 1;
        for(int i = 1;i <= target;++i)
        {
            for(auto num : nums)
            {
                if(num <= i)
                    dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        // sort(nums.begin(),nums.end());
        // int res = 0;
        // BackCore(nums,target,0,res);
        // return res;
        return DpCore(nums,target);
       // return DFS(nums,target);


    //    map<int,int> memo;
    //    return DFSMemo(nums,target,memo);
    }

};
