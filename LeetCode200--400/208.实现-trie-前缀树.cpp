/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    bool isString;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isString = false;
        memset(next,0,sizeof(next));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root = this;
        for(const auto& ch : word)
        {
            //方法一
            // root = root->next[ch - 'a'];
            // if(root == nullptr)
            //     root = new Trie();
            // //root = root->next[ch - 'a'];
            //方法二  这种操作和链表的next是一样的道理  while(node->next)  而不是while(node)
            if(root->next[ch - 'a'] == nullptr)
                root->next[ch - 'a'] = new Trie();
            root = root->next[ch - 'a'];
        }
        root->isString = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* root = this;
        for(const auto& ch : word)
        {
            root = root->next[ch - 'a'];
            if(root == nullptr)
                return false;
        }
        return root->isString;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* root = this;
        for(const auto& ch : prefix)
        {
            root = root->next[ch - 'a'];
            if(root == nullptr)
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

