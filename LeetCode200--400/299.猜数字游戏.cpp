/*
 * @lc app=leetcode.cn id=299 lang=cpp
 *
 * [299] 猜数字游戏
 */

// @lc code=start
class Solution {
public:
//hash 问题在于存储下标还是值  或者值的个数
//分类讨论 对于公牛，重要的是位置和对应的数字的匹配，所以hash表存储上述信息
//而对于cows，因为上述计算bull，已经排除了位置的信息，下面就是统计字母的个数，所以存储字母及其个数

    string getHint(string secret, string guess) {
        int match = 0;
        int sum = 0;
        for(int i = 0;i < secret.size();++i)
        {
            if(secret[i] == guess[i])
                ++match;
        }
        int dp[10];
        memset(dp,0,sizeof(dp));
        for(auto ch : secret)
        {
            ++dp[ch - '0'];
        }
        for(auto ch : guess)
        {
            if(dp[ch - '0']) //如果直接写为 dp[]-- ，会出错
            {
                --dp[ch - '0'];
                ++sum;
            }
        }
        return to_string(match) + "A" + to_string(sum - match) + "B";
    }
};
// @lc code=end

