/*
 * @lc app=leetcode.cn id=720 lang=cpp
 *
 * [720] 词典中最长的单词
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
        bool Search(const string& word)
        {
            Trie* root = this;
            for(auto ch : word)
            {
                root = root->next[ch - 'a'];
                if(!root->IsString)
                    return false;
            }
            return root->IsString;
        }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        // sort(words.begin(),words.end(),[](const string& str1,const string& str2)
        // {
        //     return str1.size() != str2.size() ? str1.size() > str2.size() : str1 < str2;
        // }
        // );
        // unordered_set<string> hash;
        // for (auto word : words) 
        //     hash.insert(word);
        // for (auto word : words) 
        // {
        //     for (int i = 1; i <= word.size(); ++i)
        //     {
        //         if(hash.find(word.substr(0, i)) == hash.end()) 
        //             break;
        //         if(i + 1 >= word.size())
        //             return word;
        //     }
        // }
        // return "";
        Trie* root = new Trie();
        for(auto word : words)
            root->Insert(word);
        string res = "";
        for(auto word : words)
        {
            if(root->Search(word))
            {
                if(word.size() > res.size() || (word.size() == res.size() && word < res))
                    res = word;
            }
        }
        return res;
    }
};
// @lc code=end

