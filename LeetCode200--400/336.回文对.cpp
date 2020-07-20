/*
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 */

// @lc code=start
class Solution {
public:
//最暴力的方法 双层循环超时
    bool IsSym(const string& word)
    {
        int left = 0;
        int right = word.size() - 1;
        while(left < right)
        {
            if(word[left] != word[right])
                return false;
            ++left;
            --right;
        }
        return true;
    }
//如果采用前缀树 isstring 可以设为int 存储单词对应的下标 而不是true false
    vector<vector<int>> GMT(vector<string>& words)
    {
        vector<vector<int>> res;
        int len = words.size();
        for(int i = 0;i < len - 1;++i)
        {
            for(int j = i + 1;j < len;++j)
            {
                if(IsSym(words[i] + words[j]))
                {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    res.push_back(temp);
                }
                if(IsSym(words[j] + words[i]))
                {
                    vector<int> temp;
                    temp.push_back(j);
                    temp.push_back(i);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        return GMT(words);
    }
};
// @lc code=end

