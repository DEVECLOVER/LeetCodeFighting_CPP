/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
// 抓住关键点，有序的数组，
//[AC]
    int MaxCount = 1; //允许数字出现的最大次数，如果两次，改为2即可
    int GMT(vector<int>& nums)
    {
        int len = nums.size();
        if(len <= MaxCount) return len;
        int index = MaxCount;
        for(int i = MaxCount;i < len;++i)  // 分析到直接从maxcount开始即可
        {
            if(nums[index - MaxCount] != nums[i]) // 关键在于判断  i 和 相差maxcount数据是否相同
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
    int removeDuplicates(vector<int>& nums) {
        return GMT(nums);
    }
};
// @lc code=end

