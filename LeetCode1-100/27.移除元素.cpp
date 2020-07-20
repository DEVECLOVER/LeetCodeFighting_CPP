/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
// 走一遍即可
//[AC]
    int GMT(vector<int>& nums,int val)
    {
        int index = 0;
        for(int i = 0;i < nums.size();++i)
        {
            if(nums[i] != val)
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
    int removeElement(vector<int>& nums, int val) {
        return GMT(nums,val);
    }
};
// @lc code=end

