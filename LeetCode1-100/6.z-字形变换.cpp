/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
//第一遍自己根本没有想到这个解法，这次还是很好想的。
//思维模式。
// [AC]
    string MultiArr(string s,int num)
    {
        if (num == 1 || s.size() <= num) 
            return s;
        vector<string> rows(num,"");
        int index = 0;
        int flag = -1;

        for (auto c : s) {
            rows[index] += c;
            if (index == 0 || index == num - 1) 
                flag = -flag;
            index += flag;
        }
        string ret;
        for (string row : rows) ret += row;
        return ret;
    }
    string convert(string s, int numRows) {
    
    return MultiArr(s,numRows);


    }
};
// @lc code=end

