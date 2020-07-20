/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
// 好好反思，得记载个数。 [NAC]
    int UglyCode(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> dp(len,1);
        int maxlen = 1;
        int count = 0;
        for(int i = 0;i < len;++i)
        {
            int temp = 0;
            for(int j = 0;j < i;++j)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i],1 + dp[j]);
                    if(dp[i] > maxlen)
                    {
                        maxlen = dp[i];
                        count = 0;
                        temp = 0;
                    }
                    else if(dp[i] == maxlen)
                        count += (++temp);
                }
            }
            if(dp[i] == maxlen)
            {
                ++count;
            }
        }
        return count;
    }
    int New(vector<int>& nums)
    {
        int len = nums.size();
        vector<pair<int,int>> dp(len,{1,1});  // 长度和个数
        int maxlen = 1;
        int count = 0;
        for(int i = 0;i < len;++i)
        {
            bool flag = false;
            for(int j = 0;j < i;++j)
            {
                if(nums[j] < nums[i])
                {
                    dp[i].first = max(dp[i].first,1 + dp[j].first);
                    if(dp[i].first > maxlen)
                    {
                        maxlen = dp[i].first;
                        dp[i].second = dp[j].second;
                        flag = true;
                    }
                    else if(dp[i].first == maxlen)
                    {
                        if(flag)
                            dp[i].second += dp[j].second;
                        else
                        {
                            dp[i].second = dp[j].second;
                            flag = true;
                        }
                        
                    }
                }
            }
        }
        for(auto item : dp)
        {
            if(item.first == maxlen)
                count += item.second;
        }
        return count;
    }
//  [AC]  极大的教训啊，思路没有搞清楚。
    int New3(vector<int>& nums)
	{
		int len = nums.size();
		vector<pair<int, int>> dp(len, { 1,1 });  // 长度和个数
		int maxlen = 1;
		int count = 0;
		for (int i = 0; i < len; ++i)
		{
			bool flag = false;
			for (int j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
				{
					if (1 + dp[j].first > dp[i].first)
					{
						dp[i].first = 1 + dp[j].first;
						dp[i].second = dp[j].second;
					}
					else if (dp[i].first == 1 + dp[j].first)
					{
						dp[i].second += dp[j].second;
					}
				}
			}
			maxlen = max(maxlen, dp[i].first);
		}
		for (auto item : dp)
		{
			if (item.first == maxlen)
			{
				count += item.second;
			}
			// cout << "长度：" << item.first << "个数：" <<  item.second << endl;
		}
		return count;
	}
    int findNumberOfLIS(vector<int>& nums) {
        //return UglyCode(nums);
        return New3(nums);
    }
};
// @lc code=end

