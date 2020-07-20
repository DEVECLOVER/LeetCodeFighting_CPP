/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
//还是之前的回溯套路  结束条件  继续条件 以及确定好选择的范围  层数的推进 数据的更新
//两种实现方式  加法和减法  
//快速剪枝  及时判断去掉不满足的情况
//双百战绩 一次过  采取减法
//如果采用加法  还得需要变量  sum == n  思路一样的
    void Back(vector<int>& nums,vector<vector<int>>& result,int index, int n,int k)
    {
        if(k < 1)
        {
            if(n == 0)
                result.push_back(nums);
            return;
        }
        //这里 i <= n  是剪枝，后面的没必要判断了
        for(int i = index;i <= n && i < 10;++i)
        {
            nums.push_back(i);
            Back(nums,result,i + 1,n - i,k - 1);
            nums.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        vector<vector<int>> result;
        Back(nums,result,1,n,k);
        return result;
    }
};
// @lc code=end

