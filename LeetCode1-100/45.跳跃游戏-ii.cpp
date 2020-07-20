/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int GMT(vector<int>& nums)
    {
       int count = 0;
        int len = nums.size();
        if(len < 2)
            return 0;
        if(nums[0] >= len - 1)
            return 1;
        ++count;
        int maxpos = 0;
        int index = 0;
        //这个方法有个局限，因为题目给定的是一定可以完成，如果不能完成，这个就是个死循环
        //比如 [3 2 1 0 4]
        for(int i = 0;i < len - 1;)
        {
            ++count;
            for(int j = i + 1;j <= i + nums[i];++j)
            {
                if(j + nums[j] >= len - 1)
                    return count;
                else
                {
                    if(j + nums[j] > maxpos)
                    {
                        maxpos = j + nums[j];
                        index = j;
                    }
                }
            }
            i = index;
            //应对死循环
            //i = max(++i,index);
        }
        return count;
    }
    int jump(vector<int>& nums) {
        int count = 0;
        int len = nums.size();
        if(len < 2)
            return 0;
        if(nums[0] >= len - 1)
            return 1;
        ++count;
        int maxpos = 0;
        int index = 0;
        //第一想法，发现是不行的,因为中间出现元素0  比如[2 2 0 1 1]
        // for(int i = 0;i < len - 1;)
        // {
        //     ++count;
        //     for(int j = i + 1;j <= i + nums[i];++j)
        //     {
        //         if(j + nums[j] >= len - 1)
        //             return count;
        //     }
        //     i += nums[i]; //关键就在于如何更新新的坐标值
        // }
        //第二想法，上述更新是错误的，后来看了题解的贪心算法改为了下述
        //当时上面的方法错误之后，就想到了要这么更新值，但是脑海中就想着尝试动态规划
        //便没有继续深入思考了，其实并不难
        for(int i = 0;i < len - 1;)
        {
            ++count;
            for(int j = i + 1;j <= i + nums[i];++j)
            {
                if(j + nums[j] >= len - 1)
                    return count;
                else
                {
                    if(j + nums[j] > maxpos)
                    {
                        maxpos = j + nums[j];
                        index = j;
                    }
                }
            }
            i = index;
        }
        return count;
//第二想法，动态规划，从后向前,真的没想到，这个方法还是超时了，最后一个测试没有通过
//令我诧异的是，提接中没有一个人提到动态规划算法
//都是清一色的贪心，大家的水准都很高啊
        // int len = nums.size();
        // if(len < 2)
        //     return 0;
        // vector<int> dp(len,len);
        // for(int i = len - 2;i >= 0;--i)
        // {
        //     if(nums[i] + i >= len - 1)
        //         dp[i] = 1;
        //     else
        //     {
        //         for(int j = i + 1;j <= i + nums[i];++j)
        //         {
        //             dp[i] = min(dp[i],1 + dp[j]);
        //         }
        //     }

        // }
        // return dp[0];
    //贪心算法，其中的贪心策略也是自己开始考虑过的，但是自己没有想到好的代码实现
        // int end = 0;
        // int maxpos = 0;
        // int count = 0;
        // for(int i = 0;i < nums.size() - 1;++i)
        // {
        //     maxpos = max(maxpos,i + nums[i]);
        //     if(i == end)//这样的转换真的很妙，在第一个解法中，我的想法就是跳转到走的最远的那个，但是代码不简洁
        //     {
        //         end = maxpos;
        //         ++count;
        //     }
        // }
        // return count;

    }
};
// @lc code=end

