/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> flag;
        for(auto i : nums)
        {
            flag[i] = false;
        }
        int maxlength = 0;
        for(auto i : nums)
        {
            if(flag[i])
            {
                continue;
            }
            int len = 1;
            for(int j = i + 1;flag.find(j) != flag.end();++j)
            {
                ++len;
                flag[j] = true;
            }
           for(int j = i - 1;flag.find(j) != flag.end();--j)
            {
                ++len;
                flag[j] = true;
            }
            maxlength = max(maxlength,len);

        }
        return maxlength;
    }
};
// @lc code=end

