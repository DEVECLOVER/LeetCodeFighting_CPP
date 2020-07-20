/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // return nums[nums.size() >> 1];
        //随机方法 很妙
        while(true)
        {
            int candidate = nums[rand() % nums.size()];//概率超过1/2
            int count = 0;
            for(auto num : nums)
            {
                if(candidate == num)
                    ++count;
            }
            if(count > (nums.size() >> 1))
                return candidate;
        }
        return -1;


    }
};
// @lc code=end

