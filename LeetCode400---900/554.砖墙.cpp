/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution {
public:
//思考的到位  好好反思总结
//最先想到的还是挨个遍历，挨个计算，没有深思一步
    int leastBricks(vector<vector<int>>& wall) {
        map<int,int> hashmap;
        int maxcount = 0;
        for(auto w : wall)
        {
            int sum = 0;
            for(int i = 0;i < w.size() - 1;++i)
            {
                sum += w[i];
                ++hashmap[sum];
                maxcount = max(maxcount,hashmap[sum]);
            }
        }
        return wall.size() - maxcount;
    }
};
// @lc code=end

