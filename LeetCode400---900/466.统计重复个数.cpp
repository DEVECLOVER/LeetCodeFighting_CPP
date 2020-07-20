/*
 * @lc app=leetcode.cn id=466 lang=cpp
 *
 * [466] 统计重复个数
 */

// @lc code=start
class Solution {
public:
//这是最直接的想法，但是超时了  【NAC】
    int Brute(string s1,int n1,string s2 ,int n2)
    {
        string str1 = "";
        for(int i = 0;i < n1;++i)
            str1 += s1;
        string str2 = "";
        for(int i = 0;i < n2;++i)
            str2 += s2;
        int count = 0;
        int index = 0;
        int objlen = str2.size();
        for(char ch : str1)
        {
            if(ch == str2[index])
            {
                ++index;
                if(index == objlen)
                {
                    ++count;
                    index = 0;
                }
            }
        }
        return count;
    }
//下面一直想着改进上面的暴力方法，但是尝试都没完全成功
//但我坚信这个方法是可行的
//第一个想法，截取前面的字符到后面，但是不适用于s1 = aaa,s2 = aa这种情况，只适用于 s1 = baba,s2 = ab
    int GMT1(string s1,int n1,string s2,int n2)
    {
        int count1 = 0;
        int index = 0;
        for(auto ch : s1)
        {
            if(ch == s2[index])
            {
                ++index;
                if(index == s2.size())
                {
                    ++count1;
                    index = 0;
                }
            }
        }
        int len1 = s1.size();
        index = 0;
        for(;index < len1;++index)
        {
            if(s1[index] == s2[0])
                break;
        }
        s1 = s1.substr(index) + s1.substr(0,index);
        index = 0;
        int count2 = 0;
        for(auto ch : s1)
        {
            if(ch == s2[index])
            {
                ++index;
                if(index == s2.size())
                {
                    ++count2;
                    index = 0;
                }
            }
        }
        return count1 == count2 ? ((count1 * n1) / n2) : ((count1 * n1 + n1 - 1) / n2);
    }
//基于上面的问题，又改进了下一版，不是用单个分析，采用拼接分析，想着考察 2 * s1 与 s1 的匹配个数关系，确定后便可以推广到n1了
//但是又出现了问题，事实上，从 2 * s1 得出的结论并不适用与 3 * s1的，
//反例就是 s1 = baba  s2 = baab, 
//稍微计算你会发现：
//n1 = 1  -> m = 0
//n1 = 2  -> m = 1
//n1 = 3  -> m = 2
//n1 = 4  -> m = 2
//出现的规律不是线性的，怎么办呢？
    int CountPart(string s1,string s2)
    {
        int count = 0;
        int index = 0;
        for(auto ch : s1)
        {
            if(ch == s2[index])
            {
                ++index;
                if(index == s2.size())
                {
                    ++count;
                    index = 0;
                }
            }
        }
        return count;
    }
    int GMT2(string s1,int n1,string s2,int n2)
    {
        int count1 = CountPart(s1,s2);
        s1 = s1 + s1;
        int count2 = CountPart(s1,s2);
        return count2 == 2 * count1 ? ((count1 * n1) / n2) : n1 & 1 ? count2 * (n1 >> 1) +  count1 : count2 * (n1 >> 1);
    }


//如何优化呢，因为存在基础单元，我们可以从这个入手
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        //return Brute(s1,n1,s2,n2);
        return GMT2(s1,n1,s2,n2);
    }
};
// @lc code=end

