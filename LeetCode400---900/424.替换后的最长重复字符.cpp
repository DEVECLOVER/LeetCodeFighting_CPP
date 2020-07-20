/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution {
public:
//如何分析这个问题呢？ 
//滑动窗口扫描时，统计窗口中字符的个数，直到需要变动的个数大于k时
//是可以将窗口直接向前移动的，因为左边的已经统计过了，靠近边缘
//关键点：如何统计需要变动的次数，当前字符的总长度减去该字符中出现次数最多字符的个数
//一般思考的话，可能会想使用hashmap，可以更加简洁是上述功能呢？
    int GMT(string s,int k)
    {
        int left = 0;
        int right= 0 ;
        int maxcount = 0;
        int res = 0;
        int dp[26];
        memset(dp,0,sizeof(dp));
        while(right < s.size())
        {
            ++dp[s[right] - 'A'];
            maxcount = max(maxcount,dp[s[right] - 'A']);//maxcount记录迄今为止出现次数最多字符的
            if(right - left + 1 - maxcount > k) //计算得到需要变动的次数
            {
                --dp[s[left] - 'A'];
                ++left;
            }
            res = max(res,right - left + 1);
            ++right;
        }
        return res;
    }
    int characterReplacement(string s, int k) {
        return GMT(s,k);
    }
};
// @lc code=end

