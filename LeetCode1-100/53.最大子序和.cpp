/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution {
public:
//[NAC]
    int UglyCode(vector<int>& nums)
    {
        //第一次尝试写动态规划，找到的状态转移公式是错误的，吸取经验教训
        int len = nums.size();
        int dp[len][len];
        memset(dp,0,sizeof(dp));
        int maxsum = nums[0];
        for(int i = 0;i < len;++i)
            dp[i][i] = nums[i];
        for(int i = 0;i < len - 1;++i)
        {
            for(int j = i + 1;j < len;++j)
            {
                //  比如数组 4 -1 2 ，由下述公式计算的最大值是6，是错误的。因为不连续
                //实际上求的是整个数组中
                dp[i][j] = max(dp[i][j - 1],max(dp[i][j - 1] + nums[j],nums[j]));
                maxsum = max(maxsum,dp[i][j]);
            }
        }
        return maxsum;
    }
    //【AC】
    int Kadane(vector<int>& nums)
    {
        int left = 0;
        int right = 0;
        int len = nums.size();
        if(len < 1)
        {
            return 0;
        }
        int result = nums[0];
        int temp = nums[0];
        for(int i = 1;i < len;++i)
        {
            temp = max(temp + nums[i],nums[i]);
            result = max(result,temp);
        }
        return result;
    }
    //添加一个要求，求出上述连续子序列的左右边界
    //比如对于 -1  -2  （-2  -1）  关键点就是左边界什么时候改变
    //如果直接求，不好做，但是右边界是可以很好确定的，而且最大值也已经确定了，
    //那么据此便可以计算出左边界了
    //但是这样是没有多大意思的，很没有成就感
    //就像用代数去做几何题，失去了趣味
    //[AC]
    int KadaneDeeper1(vector<int>& nums)
    {
        int left = 0;
        int right = 0;
        int len = nums.size();
        if(len < 1)
        {
            return 0;
        }
        int result = nums[0];
        int temp = nums[0];
        int sideresult = 0;
        for(int i = 1;i < len;++i)
        {
            temp = max(temp + nums[i],nums[i]);
            if(temp > result)
            {
                result = temp;
                right = i;  //最后确定了右边界
            }
        }
        for(int i = right;i >= 0;--i)
        {
             result -= nums[i];
             if(result == 0)
             {
                left = i;
                break;
             }
        }
        for(int i = left;i <= right;++i)
            sideresult += nums[i];
        return sideresult;
    }
    //后来在题解中看到有人也进一步提出了这个问题
    //给出了比我这更好的想法
    //我的是转化的思维，他的更加妙，因为提出了新方法，思路很好，很值得借鉴
    //问题就出在如何确定左边界，如何办呢？
    //局部左边界和全局左边界
    //[AC]
    int Kadanedeeper2(vector<int>& nums)
    {
        int localleft = 0;
        int right = 0;
        int left = 0;
        int temp = 0;
        int maxsum = INT_MIN;
        for(int i = 0;i < nums.size();++i)
        {
            if(temp + nums[i] > nums[i])
            {
                temp = temp + nums[i];
            }
            else
            {
                temp = nums[i];
                localleft = i;
            }
            if(temp > maxsum)
            {
                left = localleft;
                right = i;
                maxsum = temp;
            }
        }
        maxsum = 0;
        for(int i = left;i <= right;++i)
            maxsum += nums[i];
        return maxsum;
    }
    //分治算法
   // 如果运用滑动窗口也是可以的。确定右移的条件。 
    int maxSubArray(vector<int>& nums) {
        return Kadanedeeper2(nums);
    }
};
// @lc code=end

