/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
//即能否拆分成两个子序列，分别对应 s1  s2
//从动态规划角度思考，也容易想到 dp[i][j],s1 的前 i 个字符和 s2 的前j个字符构成s3的
//但是对于状态转移方程，自己还是有点犹疑，不敢分析，没有自信。还是要好好锻炼
//【AC】
    bool DpCore(string s1,string s2,string s3)
    {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1 + len2 != len3)
            return false;
        vector<vector<bool>> dp(len1 + 1,vector<bool>(len2 + 1,false));
        dp[0][0] = true;
        for(int i = 1;i <= len2;++i)
            dp[0][i] = s2.substr(0,i) == s3.substr(0,i);
        for(int i = 1;i <= len1;++i)
            dp[i][0] = s1.substr(0,i) == s3.substr(0,i);
        for(int i = 1;i <= len1;++i)
        {
            for(int j = 1;j <= len2;++j)
            {
                //之前总结的一句话初始化，在这里无法统一
                // if(i == 1 || j == 1)
                // {
                //     dp[i][j] = (i > 1 ? s1.substr(0,i) == s3.substr(0,i) : j > 1? s2.substr(0,j) == s3.substr(0,j) : true);
                // }
                // else
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);

            }
        }
        return dp[len1][len2];
    }
//事实上，拿到这个题目，要求是交错排序，应该立马想到递归实现的，
//如果做不到这一点，你的递归理解还是不够深入的，就像之前的扰乱字符串那样，很明显的递归特点
//还有 多链表合并，多思考 多思考 多思考！
//【NAC】  存在太多的重复子问题   超时
    bool Violent(const string& str1,int index1,const string& str2,int index2,const string& str3,string res)
    {
        //这种方法太笨了，应该在过程中剪枝，这个是所有最后在判断
        if(res == str3 && index1 == str1.size() && index2 == str2.size())
            return true;
        bool ans = false;
        //后序遍历
        if(index1 < str1.size())
        {
            ans |= Violent(str1,index1 + 1,str2,index2,str3,res + str1[index1]);
        }
        if(index2 < str2.size())
        {
            ans |= Violent(str1,index1,str2,index2 + 1,str3,res + str2[index2]);
        }
        return ans;
    }
    //【AC】
    bool memorandum(const string& str1,int index1,const string& str2,int index2,const string& str3,int index3,map<pair<int,int>,bool>& memo)
    {
        if(index1 == str1.size())
            return str2.substr(index2) == str3.substr(index3);
        if(index2 == str2.size())
            return str1.substr(index1) == str3.substr(index3);
        if(memo.count({index1,index2}))
            return memo[{index1,index2}];
        bool ans = false;
        if(((str1[index1] == str3[index3]) && memorandum(str1,index1 + 1,str2,index2,str3,index3 + 1,memo))
            || ((str2[index2] == str3[index3]) && memorandum(str1,index1,str2,index2 + 1,str3,index3 + 1,memo)) ) 
            ans = true;
        memo[{index1,index2}] = ans;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        map<pair<int,int>,bool> memo;
        //return Violent(s1,0,s2,0,s3,"");
        return memorandum(s1,0,s2,0,s3,0,memo);
    }
};
// @lc code=end

