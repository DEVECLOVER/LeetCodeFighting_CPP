/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
class Trie
{
    public:
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
            root->IsString = true;
        }
        bool DFSSearch(Trie* root,const string& word,int count,int index)
        {
            if(count > 1)
                return false;
            if(index >= word.size())
                return root->IsString && count == 1;
            for(int i = 0;i < 26;++i)
            {
                if(root->next[i] == nullptr)
                    continue;
                //重点在于下面的逻辑 
                if(i == word[index] - 'a')
                {
                    //不能直接写为  return DFS，一旦返回false，还可以接着走for循环，而不是直接退出了
                    if(DFSSearch(root->next[i],word,count,index + 1))  
                        return true;
                }
                else
                {
                    if(DFSSearch(root->next[i],word,count + 1,index + 1))
                        return true;
                }
            }
            return false;
        }

};
class MagicDictionary {
public:
    Trie* root;
    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new Trie();
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(auto word : dict)
            root->Insert(word);
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        return root->DFSSearch(root,word,0,0);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

