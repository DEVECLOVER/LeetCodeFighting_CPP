/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */

// @lc code=start
class Solution {
public:
//递归  关键如何分析的呢？
//分为两部分，构造笛卡尔积，整体思路和 构造二叉搜索树类似（数字0~n构造二叉搜索树)
//关键在于0数字的处理
//字符转换为整数，如果等于0，且字符长度大于1，则跳过，指针后移，直到不为0
//重点就是，如何对于0如何处理，分析的全面，代码思路要清晰
    void GenCore(string str,vector<string>& res)
    {
        //吸取教训，单单这个判断是不够的，无法检测出 010，即末尾为0的情况
        // if(stol(str) == 0 && str.size() > 1)
        //     return;
        if(str[0] == '0')
        {
            if(str.size() > 1)
            {
                //将开头的条件，转移到这来，这个条件也不能 与外围的条件相与
                if(str.back() != '0')
                    res.push_back("0." + str.substr(1));
            }
            else
                res.push_back(str);
        }
        else if(str.size() == 1 || str.back() == '0')
            res.push_back(str);
        else
        {
            for(int i = 1;i < str.size();++i)
                res.push_back(str.substr(0,i) + '.' + str.substr(i));
            res.push_back(str);
        }
    }
    vector<string> ambiguousCoordinates(string S) {
        int len = S.size();
        S = S.substr(1,len - 2);
        vector<string> res;
        for(int i = 1;i < S.size();++i)
        {
            //问题就出在这个判断是放在调用者还是被调用者
            // string str = S.substr(0,i);
            // if(stol(str) == 0 && str.size() > 1)
            //     continue;
            vector<string> left;
            vector<string> right;
            GenCore(S.substr(0,i),left);
            GenCore(S.substr(i),right);
            for(auto fir : left)
            {
                for(auto sec : right)
                    res.push_back('(' + fir + ", " + sec + ')');
            }
        }
        return res;
    }
};
// @lc code=end

