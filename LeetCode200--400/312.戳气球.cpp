/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
//对于编程的题目，如果不是特别好抽象分析的，不要想着推导数学规律，利用一个公式就给解决的
//基本上，都是要借用穷举的，然后优化
//回溯法   超时  锻炼思维
//动态规划法
    void CoinsCore(vector<int>& nums,int index,long long& tempsum,long long& maxnum)
    {
        if(index == nums.size())
        {
            maxnum = max(maxnum,tempsum);
            return ;
        }
        for(int i = 0;i < nums.size();++i)
        {
            if(nums[i] < 0)
                continue;
            int left = i - 1;
            while(left >= 0 && nums[left] < 0)
                --left;
            left = left < 0 ? 1 : nums[left];
            int right = i + 1;
            while(right < nums.size() && nums[right] < 0)
                ++right;
            right = right >= nums.size() ? 1 : nums[right];
            int coins = left * nums[i] * right;
            tempsum += coins;
            int tempnum = nums[i];
            nums[i] = -1;
            //注意这里是index + 1 ,代表的是层数的增加，而不是 i + 1, i代表的是元素的下标
            CoinsCore(nums,index + 1,tempsum,maxnum);
            nums[i] = tempnum;
            tempsum -= coins;//相当于之前的pop_back()
        }
    }
    int maxCoins(vector<int>& nums) {
        //暴力回溯
        // long long tempsum = 0;
        // long long maxnum = 0;
        // CoinsCore(nums,0,tempsum,maxnum);
        // return maxnum;

        //巧妙的定义状态方程
        //之前自己定义时dp[i][j]是i 和 j 也都包含在内的
        //对比一下，有什么优缺点呢？如果采用后者，状态转移方程是什么样的呢？
        //就像字符串处理，前面添加空格。影响的都是初始化
        int arrlen = nums.size();
        vector<int> newnums(arrlen + 2,1);
        for(int i = 0;i < arrlen;++i)
            newnums[i + 1] = nums[i];
        arrlen += 2;
        vector<vector<int>> dp(arrlen,vector<int>(arrlen,0));
        for(int len = 3;len <= arrlen;++len)
        {
            for(int i = 0;i + len <= arrlen;++i)
            {
                int j = i + len - 1;
                for(int k = i + 1;k < j;++k)
                {
                    dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] + newnums[i] * newnums[k] * newnums[j]);
                }
            }
        }
        return dp[0][arrlen - 1];
        


    }
};
// @lc code=end

