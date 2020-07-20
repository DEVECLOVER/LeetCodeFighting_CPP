/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
public:
// 第二次思考，总体思路是对的，每次就是三种选择而已，只要涉及到选择的，DFS即可。
// 关键点，dot的个数是否达到三个了，字符是否结尾了。
//第一点，字符串大小是有限制的，在比较下的区间内变动而已
//  4 ~ 12   向里面添加点
//每一段长度为1~3
// [AC]
    void BackCore(vector<string>& result,int count,string str,string ip)
    {
        if(count == 4)
        {
            if(str.empty())
                result.push_back(ip);
            return ;
        }
        for(int i = 1;i < 4;++i)
        {
            if(str.size() < i) 
                break;
            int num = stoi(str.substr(0,i));
            //前面一个条件是排除  首字符为 0 转换为长度不等了
            // 第二遍思考，前面的数字的判断是自己刚开始所没有想到的。要注意！！！
            if(i != to_string(num).size() || num > 255)  // 如果改为  str[0] == '0'  则无法判断 0000 了 
                continue;
            BackCore(result,count + 1,str.substr(i),ip + str.substr(0,i) + (count == 3?"" : "."));
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        BackCore(result,0,s,"");
        return result;
    }   
};
// @lc code=end

