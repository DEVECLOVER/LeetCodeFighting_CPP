/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
//方法一：回溯算法
//愚蠢的竟然写出了上面的代码，可恨至极啊！反思吧
    void BackCore(const string& str,const int& len,int& count,int index)
    {
        if(index >= len)
            ++count;
        for(int i = index;i < len;++i)
        {
            BackCore(str,len,count,i + 1);
            if(i + 1 < len && stol(str.substr(i,2)) < 27)
                BackCore(str,len,count,i + 2);
        }
    }
    //暴力解超时  思路和爬楼梯  青蛙跳是一样的，分析问题的能力
    //每次至多取两个数  一次至多爬两层
    //[NAC]
    int Violent(const string& str,const int& len,int index)
    {
        if(index >= len)
            return 1;
        if(str[index] == '0')
            return 0;
        int ans1 = Violent(str,len,index + 1);
        int ans2 = 0;
        if(index + 1 < len && stol(str.substr(index,2)) < 27)
            ans2 = Violent(str,len,index + 2);
        return ans1 + ans2;
    }
// 第二遍，很自然的写出这样的代码，这是正常的分析方法，思路和后面的IP地址是一样的。
// 因为存在太多的重复子问题，超时
//[NAC]
    void DFS(string str,int& count)
    {
        if(str.size() < 1)
        {
            ++count;
            return;
        }
        for(int i = 1;i < 3;++i)
        {
            if(i > str.size())
                break;
            string temp = to_string(stol(str.substr(0,i)));
            if(i != temp.size() || stol(temp) > 26 || stol(temp) < 1)
                break;
            DFS(str.substr(i),count);
        }
    }
    int GMT(string s)
    {
        int count = 0;
        DFS(s,count);
        return count;
    }
// 下面才是一步步的优化，通过添加备忘录，在优化到动态规划
// 如何利用备忘录呢？发现处理不了
// [NAC]
    void DFSMemo(string str,int& count,unordered_map<string,bool>& memo)
    {
        if(memo.count(str))
        {
            if(memo[str])
            {
                ++count;
                return;
            }
        }
        memo[str] = false;
        if(str.size() < 1)
        {
            ++count;
            memo[str] = true;
            return;
        }
        for(int i = 1;i < 3;++i)
        {
            if(i > str.size())
                break;
            string temp = to_string(stol(str.substr(0,i)));
            if(i != temp.size() || stol(temp) < 1 || stol(temp) > 26)
                break;
            DFSMemo(str.substr(i),count,memo);
        }
    }
    int GMTDeep(string s)
    {
        unordered_map<string,bool> memo;
        int count = 0;
        DFSMemo(s,count,memo);
        return count;
    }
// [AC]
// 一旦认识了DFS，这个动态规划的解法还是很好理解的。
    int UglyDP(string s)
    {
        if(s[0]=='0') 
            return 0;
        vector<int> dp(s.size()+1,1);
        for(int i=1;i<s.size();i++)
        {
            if(s[i]=='0')
                if (s[i-1]=='1'||s[i-1]=='2') 
                    dp[i+1]=dp[i-1];//计数要回退一个
                else
                    return 0;
            else if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6'))
                dp[i+1]=dp[i]+dp[i-1];
            else
                dp[i+1]=dp[i];
        }
        return dp[s.size()];
    }
// 将上述的动规优化一下，只和前两个相关。就像斐波那契爬楼梯那样分析
//[AC]
    int DP(string s)
    {
        if(s.size() < 1 || s[0] == '0')
            return 0;
        int pre = 1;
        int cur = 1;
        int len = s.size();
        for(int i = 1;i < len;++i)
        {
            int temp = cur;
            if(s[i] == '0')
            {
                if(s[i - 1] == '1' || s[i - 1] == '2')
                    cur = pre;
                else
                {
                    return 0;
                }
            }
            else if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))
                cur += pre;
            pre = temp;
        }
        return cur;
    }
    int numDecodings(string s) {
        //return UglyDP(s);
        //return GMT(s);
        //return GMTDeep(s);
        return DP(s);
    }

};
// @lc code=end

