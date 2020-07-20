/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
//建立一个hash即可
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int,int> hashmap;
        for(auto num : nums1)
            hashmap[num] = 1;
        for(auto num : nums2)
        {
            if(hashmap[num])
            {
                res.push_back(num);
                //hashmap[num] = 0;
                hashmap.erase(num); //要么置位0  要么直接删除
            }
        }
        return res;

    }
};
// @lc code=end

