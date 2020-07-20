/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
//第一点，你应该要立马想到 DFS ，做不到这一点，说明，没有精心思考
//一定要有这种反应，必须要有
//这种双变量的递归，参考生成左右括号
//暴力DFS  超时 【NAC】
    void DFS(vector<int>& nums,const int& m,int index,int count,int curnum,int curmax,int& res)
    {
        if(index == nums.size() && count == m)
            res = min(res,curmax);
        if(index >= nums.size())
            return;
        // if(index < nums.size() )
        //     DFS(nums,m,index + 1,count,curnum + nums[index],max(curmax,curnum + nums[index]),res);
//第一遍的判断是上述，是错误的，因为，刚开始，只能是index和count同时开始加，如果按照上述逻辑，分组依然是0，却已经开始计数了
//下面两个if 即是，判断一个数作为一个新的分组  很妙
        if(index < nums.size() && index > 0 && nums[index] < INT_MAX - curnum) // 加上溢出判断 [1 INT_MAX]  如果相加便会溢出了
        {
            DFS(nums,m,index + 1,count,curnum + nums[index],max(curmax,curnum + nums[index]),res);
        }
        if(count < m)
            DFS(nums,m,index + 1,count + 1,nums[index],max(curmax,nums[index]),res);
    }
//如何将上述转换为dp,
    int splitArray(vector<int>& nums, int m) {
        int res = INT_MAX;
        DFS(nums,m,0,0,0,0,res);
        return res;
    }
};
// @lc code=end

