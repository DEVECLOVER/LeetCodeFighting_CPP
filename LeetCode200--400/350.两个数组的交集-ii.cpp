/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int,int> hashmap;
        for(auto num : nums1)
            ++hashmap[num];
        for(auto num : nums2)
        {
            if(hashmap[num])   //
            {
                --hashmap[num];
                res.push_back(num);
            }
        }
        return res;
    }
};
// @lc code=end

