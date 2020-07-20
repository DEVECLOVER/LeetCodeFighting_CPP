/*
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

// @lc code=start
class Trie
{
    public :
        bool IsString;
        Trie* next[26];
        Trie()
        {
            IsString = false;
            memset(next,0,sizeof(next));
        }
        void Insert(const string& word)
        {
            Trie* root = this;
            for(auto ch : word)
            {
                if(root->next[ch - 'a'] == nullptr) 
                    root->next[ch - 'a'] = new Trie();
                root = root->next[ch - 'a'];
            }
            root->IsString  = true; 
        }
        //关键就是这个搜索
        bool DFSSearch(const string& word,int index,int count)
        {
            Trie* root = this;
            for(int i = index;i < word.size();++i)
            {
                root = root->next[word[i] - 'a'];
                if(root == nullptr)
                    return false;
                if(root->IsString)
                {
                    if(i == word.size() - 1)
                        return count >= 1;
                    if(DFSSearch(word,i + 1,count + 1)) //不能直接输出 return dfs……
                        return true;
                }
            }
            return false;
        }
};
class Solution {
public:
//思路比较简单   快速将思路转变为代码

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> res;
        Trie* root = new Trie();
        for(auto word : words)
            root->Insert(word);
        for(auto word : words)
        {
            if(root->DFSSearch(word,0,0))
                res.push_back(word);
        }
        return res;
    }
};
// @lc code=end

