/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
//第一想法的问题，不应该只和第一个比较，而且发现重复之后，也不应该只移动一次
//但是，你知道，上面的思路也不是一无是处，包含了一定的想法。
//第一想法 发现只能匹配第一个相同的
// "abcabcbb"  输出结果是5 而不是正确的  [NAC]
    int UglyCode(string s)
    {
        int maxlen = 0;
        int left = 0;
        for(int i = 0;i < s.size();++i)
        {
            if(s[i] == s[left])
            {
                ++left;
            }
            maxlen = max(maxlen,i - left + 1);
        }
        return maxlen;
    }
//如何改进呢？也就是下面的加了个标志位 将读取过的都标记起来
//新读取的字符判断是否标记过即可，便有了下面的代码
//但是 "dvdf" 输出的2，而不是正确的答案3
//问题这才暴露出来，前面的匹配是一个关键点
//还有一个关键点就是，匹配之后的left的下标的更新问题
//第一种是++，问题是漏失匹配到后面的字符
//下面的问题是，漏失前面的  [NAC]
//问题在于，一旦发现重复了，应该从当初那个位置加一，而不是从当前的位置开始
    int GMT1(string s)
    {
        int maxlen = 0;
        int left = 0;
        vector<bool> flag(128,false);
        for(int i = 0;i < s.size();++i)
        {
            if(flag[s[i]])
            {
                left = i;
            }
            flag[s[i]] = true;
            maxlen = max(maxlen,i - left + 1);
        }
        return maxlen;
    }
//改进后，便有了下述的思路
//为了从当初的位置出发，flag中存储在应该是bool，而是字符的index信息，很好理解。
// [AC]
    int GMT2(string s)
    {
        vector<int> flag(128,-1);
        int maxlen = 0;
        int left = 0;
        for(int i = 0;i<s.size();++i)
        {
            //重点在于添加start指针 窗口法的妙用
            if(flag[s[i]] >= left) //注意点，这里不能写判断为-1，因为要匹配最近的重复位置，如 abba
            {
                left = flag[s[i]] + 1;
            }
            flag[s[i]] = i;
            maxlen = max(maxlen,i - left + 1);
        }
        return maxlen;
    }
//注意里面的字符不只是小写的
//[AC]
    int GMT3(string s)
    {
        int curlen = 0;
        int maxlen = 0;
        vector<int> dp(256,-1);
        int len = s.size();
        for(int i = 0;i < len;++i)
        {
            int preindex = dp[s[i]];
            if(preindex < 0 || i - preindex > curlen)
                ++curlen;
            else
            {
                if(curlen > maxlen)
                    maxlen = curlen;
                curlen = i - preindex; //这一步不能忘
            }
            dp[s[i]] = i;
        }
        if(curlen > maxlen)
            maxlen = curlen;
        return maxlen;  

    }
// 联系最长递增子序列
    int lengthOfLongestSubstring(string s) {
        //return GMT2(s);
        return GMT3(s);
    }
};
// @lc code=end

