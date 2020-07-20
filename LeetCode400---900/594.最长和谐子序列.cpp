/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        //dp 数组即可 
        int len = nums.size();
        int maxlen = 0;
        //int 数组初始化问题，一定整明白，这次又是野值
        // int dp[len];
        // memset(dp,1,sizeof(dp));
        //第一遍思路，问题很严重，拘泥于单例  没有认识到 [1 2 3 4]的情况
        //太过操之过急，没有沉下心分析思考
        // for(int i = 1;i < len;++i)
        // {
        //     for(int j = 0;j < i;++j)
        //     {
        //         if(abs(nums[i] - dp[j].first) < 2)
        //         {
        //                dp[i] = max(dp[i],dp[j] + 1);
        //         }
        //     }
        //     maxlen = max(maxlen,dp[i].second);
        // }
        //下标为末尾的  对应的子序列的最小值和子序列的长度
        // vector<pair<int,int>> dp;
        // for(int i = 0;i < len;++i)
        // {
        //     // dp[i].first = nums[i]; //初始化最小值为自身 ，长度为1  即自身
        //     // dp[i].second = 1;
        //     dp.push_back(make_pair(nums[i],1));
        // }
        //第二遍还是有问题，因为，每个位置都存储再次之前的最小值，而答案可能是以改值为最小值
        // for(int i = 1;i < len;++i)
        // {
        //     for(int j = 0;j < i;++j)
        //     {
        //         if(abs(nums[i] - dp[j].first) < 2)
        //         {
        //             dp[i].first = min(dp[i].first,dp[j].first);
        //             dp[i].second = max(dp[i].second,dp[j].second + 1);
        //         }
        //     }
        //     maxlen = max(maxlen,dp[i].second);
        // }
        // return maxlen;
        //因为计算的是长度，所以如果拍完序在统计就没有问题了，自己已经忘记了这一点
        //如果题目改为求此子序列的左右边界，也还是可以查找到位置的，排序这一点很重要，是自己鬼迷心窍了
        sort(nums.begin(),nums.end());
        //拍完序后使用滑动窗口便是可以的了，因为left的移动是清晰的了，如果diff 大于了1，后面的
        //元素便更是大于了，此时便可以删除掉front元素
        //拍完序，能想到下面这样简洁的思路也是很不容易的
        int left = 0;
        int right = 0;
        while(right < len)
        {
            if(nums[right] - nums[left] > 1)
                ++left;
            if(nums[right] - nums[left] == 1)
                maxlen = max(maxlen,right - left + 1);
            ++right;
        }
        return maxlen;
    }
};
// @lc code=end

