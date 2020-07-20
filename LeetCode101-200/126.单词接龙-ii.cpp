/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    //回溯即可 
    //子函数  判断两个字符知否只有一个不同

    //哈哈，思路是没有问题的  只是暴力回溯  超时了
    //如何进一步剪枝  是要好好分析递归树的
    //明天看下题解  学习DFS 和 BFS双向
    bool IsOne(string str1,string str2)
    {
        if(str1 == str2)
            return false;
        int count = 0;
        int index1 = 0;
        int index2 = 0;
        //两个长度一样
        while(index1 < str1.size())
        {
            if(str1[index1] != str2[index1])
                ++count;
            ++index1;
        }
        return count == 1? true : false;
    }
    void LadderCore(vector<string>& wordList,vector<vector<string>>& result,vector<string>& temp,int index,const int& len,const string& obj)
    {
        if(temp.back() == obj)
        {
            while(!result.empty() && temp.size() < result.back().size())
                result.pop_back();
            if(result.empty() || temp.size() <= result.back().size())
                result.push_back(temp);
            return;
        }
        if(index == len)
            return;
        for(int i = 0;i < len;++i)
        {
            if(wordList[i] == "#")
                continue;
            if(!IsOne(temp.back(),wordList[i])) //可以添加备忘录，不能每次都得比较一下
                continue;
            temp.push_back(wordList[i]);
            string tempstr = wordList[i];
            wordList[i] = "#";
            LadderCore(wordList,result,temp,index + 1,len,obj);
            wordList[i] = tempstr;
            temp.pop_back();
        }
    }
// 超时  【NAC】
    vector<vector<string>> BackCore(string beginWord, string endWord, vector<string>& wordList)
    {
        vector<string> temp;
        temp.push_back(beginWord);
        vector<vector<string>> result;
        LadderCore(wordList,result,temp,0,wordList.size(),endWord);
        return result;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        return BackCore(beginWord,endWord,wordList);
    }
};
// @lc code=end

