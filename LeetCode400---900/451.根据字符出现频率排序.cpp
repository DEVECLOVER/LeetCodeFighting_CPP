/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
//一样的优先队列或者 vector 排序即可
    string frequencySort(string s) {
        map<char,int> hashmap;
        for(auto ch : s)
            ++hashmap[ch];
        //可以直接从hashmap 转到vector
        vector<pair<char,int>> con(hashmap.begin(),hashmap.end());
        sort(con.begin(),con.end(),[](pair<char,int>& p,pair<char,int>& q)
        {
            return p.second != q.second ? p.second > q.second : p.first < q.first;
        });
        string res = "";
        for(auto ele : con)
        {
            for(int i = 0;i < ele.second;++i)
                res += ele.first;
        }
        return res;
    }
};
// @lc code=end

