/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
//暴力 超时
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // for(int i = 0;i < nums.size();++i)
        // {
        //     for(int j = i + 1;j <= i + k && j < nums.size();++j)
        //     {
        //         if(nums[j] == nums[i])
        //             return true;
        //     }
        // }
        // return false;
        map<int,int> hashmap;
        for(int i = 0;i < nums.size();++i)
        {
            if(hashmap.find(nums[i]) != hashmap.end())
            {
                if(i - hashmap[nums[i]] <= k)
                    return true;
            }
            hashmap[nums[i]] = i;

        }
        return false;
    }
};
// @lc code=end

