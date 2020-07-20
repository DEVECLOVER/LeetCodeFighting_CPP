/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 *
 * [1010] 总持续时间可被 60 整除的歌曲
 */

// @lc code=start
class Solution {
public:
//参见两数之和
//自己居然没有想到mod运算，不应该的！
//
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> dp(60);
        int count = 0;
        for(auto num : time)
        {
            int mod = num % 60;
            int gap = (mod == 0 ? 0 : 60 - mod);
            count += dp[gap];//很简洁，值得思考学习
            ++dp[mod];
        }
        return count;
    }
};
// @lc code=end

