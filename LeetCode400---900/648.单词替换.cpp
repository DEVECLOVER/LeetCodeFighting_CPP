/*
 * @lc app=leetcode.cn id=648 lang=cpp
 *
 * [648] 单词替换
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
        string Search(const string& word)
        {
            Trie* root = this;
            string res = "";
            for(auto ch : word)
            {
                res += ch;
                root = root->next[ch - 'a'];
                if(root == nullptr)
                    return word;
                if(root->IsString)
                    return res;
            }
            return word;
        }
};
class Solution {
public:
//思路基本上都是一样的
//建立前缀树 然后搜索  关键在于搜索的方式根据题目改变下
//就像前面的DFS 或者回溯  整体的框架都是一样的，不同点即是判断条件 和搜索条件
    bool SortStd(string str1,string str2)
    {
        return str1.size() != str2.size() ? str1.size() < str2.size() : str1 < str2;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        //sort(dict.begin(),dict.end(),SortStd);
        Trie* root = new Trie();
        for(const auto& word : dict )
            root->Insert(word);
        string str = "";
        string res = "";
        for(auto ch : sentence)
        {
            if(ch != ' ')
                str += ch;
            else
            {
                res += (root->Search(str) + ' ');
                str = "";
            }
        }
        return res + root->Search(str);
    }
};
// @lc code=end

