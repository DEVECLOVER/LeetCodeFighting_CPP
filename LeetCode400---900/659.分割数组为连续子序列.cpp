/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
class Solution {
public:
//贪心做的很妙  
//之前自己思考时就困在这一点上，尽量不要重新开辟序列，
//接到原来的序列上。
    bool isPossible(vector<int>& nums) {
        map<int,int> counter;
        map<int,int> chain;
        for(auto num : nums)
            ++counter[num];
        for(auto num : nums)
        {
            if(counter[num] == 0)
                continue;
            if(counter[num] > 0 && chain[num - 1] > 0)
            {
                --counter[num];
                --chain[num - 1];
                ++chain[num];
            }
            else if(counter[num] && counter[num + 1] && counter[num + 2])
            {
                --counter[num];
                --counter[num + 1];
                --counter[num + 2];
                ++chain[num + 2];
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end

