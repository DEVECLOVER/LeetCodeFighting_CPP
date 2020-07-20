/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution {
public:
//方法一  暴力回溯 
//进一步优化 备忘录
//dp 
    long long Calcsum(vector<int>& nums,int left,int right)
    {
        long long sum = 0;
        for(int i = left;i <= right;++i)
            sum += nums[i];
        return sum;
    }
    // 也就是双层for循环而已啊，思考不清楚
    void BackCore(vector<int>& nums,int& count,int index,const int& lower,const int& upper)
    {
        for(int i = index;i< nums.size();++i)
        {
            long long sum = Calcsum(nums,index,i);
            if(sum < lower || sum > upper)
                continue;
            ++count;
            BackCore(nums,count,i + 1,lower,upper);
            
        }
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int count = 0;
        BackCore(nums,count,0,lower,upper);
        return count;
    }
};
// @lc code=end

