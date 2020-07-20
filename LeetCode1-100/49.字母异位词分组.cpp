/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
// 一般性思维方法
    vector<vector<string>> GMT(vector<string>& strs)
    {
        unordered_map<string,vector<string>> con;
        vector<vector<string>> result;
        for(auto str : strs)
        {
            string temp = str;
            sort(temp.begin(),temp.end());
            con[temp].push_back(str);
        }
        for(auto num : con)
        {
            result.push_back(num.second);
        }
        return result;
    }
// 一一对应的关系，上面我们排序时，也就是确定关系。但是需要排序，能不能不排序呢？
// 将26个字符对应各个质数，利用唯一分解定理。每个字符的积是不一样的。这就是抽象，抓住本质
// 很妙的想法
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        return GMT(strs);
    }
};
// @lc code=end

