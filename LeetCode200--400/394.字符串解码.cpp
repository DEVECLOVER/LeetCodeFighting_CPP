/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
//这题自己在思考是，一直在想栈里究竟存储什么信息呢
//是从后向前遍历还是从前向后呢
    string Repeat(const string& str,int count)
    {
        string result = "";
        for(int i = 0;i < count;++i)
            result += str;
        return result;
    }
    string decodeString(string s) {
        //观察别人如何对vector进行命名的
        vector<pair<int,string>> con;
        string res = "";
        int count = 0;
        for(auto ch : s)
        {
            if(ch >= '0' && ch <= '9')
                count = (count << 3) + (count << 1) + (ch & 0xf);//小技巧加速运算
            else if(ch == '[')
            {
                con.push_back(pair(count,res));
                res = "";
                count = 0;
            }
            else if(ch == ']')
            {
                pair<int,string> curpair = con.back();
                con.pop_back();
                res = curpair.second + Repeat(res,curpair.first);
            }
            else
             res += ch;
        }
        return res;
    }
};
// @lc code=end

