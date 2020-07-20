/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
//通过hashmap   一次过 【AC】
    vector<int> GMT(vector<int>& nums,int target)
    {
        vector<int> res;
        map<int,int> hashmap;
        int len = nums.size();
        for(int i = 0;i < len;++i)
        {
            int gap = target - nums[i];
            if(hashmap.count(gap))
            {
                res.push_back(hashmap[gap]);
                res.push_back(i + 1);
                return res;
            }
            hashmap[nums[i]] = i + 1;
        }
        return res;
    }
//二分搜索即可
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        return GMT(numbers,target);
    }   
};
// @lc code=end

