/*
 * @lc app=leetcode.cn id=632 lang=cpp
 *
 * [632] 最小区间
 */

// @lc code=start
class Solution {
public:
//给定两个数组，如何找到两个相距最近的数
//现在是三个数组找最近的三个数
//没想到自己的想法居然就是正解
//今天早上想到的一个办法：利用hashmap，存储的是元素及其对应的数组编号
//然后从小到大排序，目的即是求包含所有数组编号的最小子串长度，
//于是问题转换为子串的最小长度了，这是之前做过的
//今天看了题解这正是正解，很开心啊，哈哈
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //priority_queue<pair<int,int> vector<pair<int,int>,greater<int>> pq; //第一次想用优先队列
        //但是后续滑动窗口时，不好根据下标索引，如果用map的话，自己也还不是很熟悉这般操作
        //便只好使用vector了
        //信心爆棚了吗，居然一次过，哈哈，可以的！没有什么是自己搞不好的了！
        vector<pair<int,int>> arr;
        int len = nums.size();
        for(int i = 0;i < len;++i)
        {
            for(auto num : nums[i])
                arr.push_back(make_pair(num,i));
        }
        sort(arr.begin(),arr.end(),[](pair<int,int>& p,pair<int,int>& q)
        {
            return p.first < q.first;
        });
        int left = 0;
        int right = 0;
        int wholelen = arr.size();
        map<int,int> objmap;
        map<int,int> sourcemap;
        int match = 0;
        vector<int> res;
        int minlen = INT_MAX;
        for(int i = 0;i < len;++i)
            ++objmap[i];
        //滑动窗口思路很清晰
        while(right < wholelen)
        {
            if(++sourcemap[arr[right].second] == objmap[arr[right].second])
                ++match;
            while(match == len)
            {
                if(arr[right].first - arr[left].first < minlen)
                {
                    minlen = arr[right].first - arr[left].first;
                    res.clear();
                    res.push_back(arr[left].first);
                    res.push_back(arr[right].first);
                }
                if(--sourcemap[arr[left].second] < objmap[arr[left].second])
                    --match;
                ++left;
            }
            ++right;
        }
        return res;

    }
};
// @lc code=end

