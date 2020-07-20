/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    struct Cmp
    {
        bool operator()(const pair<int,int>& p,const pair<int,int>& q )
        {
            return p.second < q.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int,int> hashmap;
        for(auto num : nums)
            ++hashmap[num];
        
        // vector<pair<int,int>> container(hashmap.begin(),hashmap.end());
        // sort(container.begin(),container.end(),[](pair<int,int>& p,pair<int,int>& q)
        // {
        //     return p.second > q.second;
        // }
        // );
        // for(int i = 0;i < k;++i)
        //     res.push_back(container[i].first);

        priority_queue<pair<int,int>,vector<pair<int, int>>,Cmp> myqueue;
        //for(auto it = hashmap.begin();it != hashmap.end();++it)
        for(auto num : hashmap)
            myqueue.push(num);
        for(int i = 0;i < k;++i)
        {
            res.push_back(myqueue.top().first);
            myqueue.pop();
        }
        return res;
    }
};
// @lc code=end

