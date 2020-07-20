/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
class WordDictionary {
private:
    bool isString;
    WordDictionary* next[26];
public:
//简单 原想着利用暴力求解的，但是不好
    /** Initialize your data structure here. */
    WordDictionary() {
        isString = false;
        memset(next,0,sizeof(next));
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        WordDictionary* root = this;
        for(const auto& ch : word)
        {
            if(root->next[ch - 'a'] == nullptr)
                root->next[ch - 'a'] = new WordDictionary();
            root = root->next[ch - 'a'];
        }
        root->isString = true;
    }
    bool DFS(WordDictionary* root,const string& word,int index)
    {
        //开头这个判断条件没考虑到
        if(root == nullptr)
            return false;
        if(index >= word.size())
            return root->isString;
        if(word[index] == '.')
        {
            //如何匹配 . ，挨个匹配
            for(int i = 0;i < 26;++i)
            {
                if(root->next[i] && DFS(root->next[i],word,index + 1))
                    return true;
            }
        }
        else
        {
            if(root->next[word[index] - 'a'])
                return DFS(root->next[word[index] - 'a'],word,index + 1);
        }
        return false;
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return DFS(this,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

