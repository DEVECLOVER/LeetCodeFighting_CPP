/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
class Solution {
public:
//先排序，然后动态规划即可
//dp[i]表示 以i下标结尾的最大结果  思路很简单
//比较关键的问题是：如何存储，不断刷新
    vector<int> DpCore(vector<int>& nums)
    {
        int sz = nums.size(),mx = 0,end = -1;
        vector<int> dp(sz,1),last(sz,-1),res;
        sort(nums.begin(),nums.end());
        for(int i = 0;i<sz;i++){
            for(int j = 0;j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[i]<=dp[j]){
                    dp[i] = dp[j]+1;
                    last[i] = j;
                    //res.push_back(nums[i]);
                }
            }
            if(dp[i]>mx){
                mx = dp[i];
                end = i;
                //res.push_back(nums[i]);
            }
        }
        for(int i = end;i!=-1;i = last[i]){//倒序输出
            res.push_back(nums[i]);
        }
        return res;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return DpCore(nums);
    }
};
// @lc code=end

