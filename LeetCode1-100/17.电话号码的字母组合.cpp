/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
//正常的回溯算法即可
// [AC]
    void CombinationCore(const vector<string>& array,const string& digits,string com,vector<string>& result,int index)
    {
        if(digits[index] == '\0')
        {
            result.push_back(com);
            return;
        }
        string str = array[digits[index] & 0xf];
        for(int i = 0;i < str.size();++i)
        {
            CombinationCore(array,digits,com + str[i],result,index + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> array = {
            "",
            "", "abc","def",
            "ghi","jkl","mno",
            "pqrs","tuv","wxyz"
        };
        vector<string> result;
        if(digits.empty())
        {
            return result;
        }
        string com = "";
        CombinationCore(array,digits,com,result,0);
        return result;
    }
};
// @lc code=end

