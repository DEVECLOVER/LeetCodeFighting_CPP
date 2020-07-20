/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
// 想法可能是，从头开始遍历，如果发现前一个字符代表的数值比后者小，说明两者是组合的。
// 那么就可以一次读取两个字符。
//[AC]
// 而这里存储的数组比正常的小，也是细节之处。
    int Violent(string s)
    {
        unordered_map<string, int> m = {{"I", 1}, {"IV", 3}, {"IX", 8}, {"V", 5}, {"X", 10}, {"XL", 30}, {"XC", 80}, {"L", 50}, {"C", 100}, {"CD", 300}, {"CM", 800}, {"D", 500}, {"M", 1000}};
        int r = m[s.substr(0, 1)];
        for(int i=1; i<s.size(); ++i)
        {
            string two = s.substr(i-1, 2);
            string one = s.substr(i, 1);
            r += m[two] ? m[two] : m[one];
        }
        return r;
    }
//[AC]  
// 教训就是，即使思路差不多，但在真正实现时，诸多细节都是很能体现能力的。
    int GMT(string s)
    {
        unordered_map<string, int> m = {{"I", 1}, {"IV", 4}, {"IX", 9}, {"V", 5}, {"X", 10}, {"XL", 40}, {"XC", 90}, {"L", 50}, {"C", 100}, {"CD", 400}, {"CM", 900}, {"D", 500}, {"M", 1000}};
        int len = s.size();
        int sum = 0;
        // for(int i = 0;i < len - 1;)
        // {
        //     string str1 = s.substr(i,1);
        //     string str2 = s.substr(i + 1,1);
        //     if(m[str1] < m[str2])
        //     {
        //         sum += m[s.substr(i,2)];
        //         i += 2;
        //     }
        //     else
        //     {
        //         sum += m[str1];
        //         ++i;
        //     }
        // }
        // 之所以改为了使用while，而不是上述的for循环，因为最后的末端不好判断的。
        while(!s.empty())
        {
            string str1 = s.substr(0,1);
            string str2 = s.substr(1,1);
            if(m[str1] < m[str2])
            {
                sum += m[s.substr(0,2)];
                s = s.substr(2);
            }
            else
            {
                sum += m[str1];
                s = s.substr(1);
            }
        }
        return sum;
    }
    int romanToInt(string s) {
        //return Violent(s);
        return GMT(s);
    }
};
// @lc code=end

