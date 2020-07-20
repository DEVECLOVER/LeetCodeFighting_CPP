/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
class Solution {
public:
//hash即可
//或者截取固定长度一一比对即可
//可能会有人第一想法是这样的，但是是有问题的，单纯通过长度也是不可取的
//重点在于每个字符的个数，而不是总的个数，这是必要条件，而不是充分条件
//【NAC】
    bool GMT(string s1,string s2)
    {
        map<char,int> hashmap;
        map<char,int> objstr;
        for(auto ch : s1)
            ++objstr[ch];
        int len = s2.size();
        int len1 = s1.size();
        for(int i = 0;i < len;++i)
        {
            if(objstr.count(s2[i]))
            {
                int j = i;
                for(;j < i + len1;++j)
                {
                    if(!objstr.count(s2[j]))
                        break;
                }
                if(j >= i + len1)
                    return true;
            }
        }
        return false;
    }
//很巧妙的方法，利用了字符串的连续的特点，left和right的前后交替
//【AC】
    bool Cool(string s1,string s2)
    {
        unordered_map<char, int> mp;
        for (auto &c: s1) 
            mp[c]++; 
        int l = 0, r = 0;
        while (r < s2.size())
        {
            char c = s2[r++];
            mp[c]--; // 入窗
            while (l < r && mp[c] < 0) //一旦判断mp[c]小于0，说明s1中不存在这个字符，接着left指针恢复原来的值
            { // 出窗
                mp[s2[l++]] ++;
            }
            //因为前面执行的r++,这里 r - l就是长度
            if (r - l == s1.size()) 
                return true;
        }
        return false;
    }
    bool checkInclusion(string s1, string s2) {
        return Cool(s1,s2);
        //return GMT(s1,s2);
     }
};
// @lc code=end

