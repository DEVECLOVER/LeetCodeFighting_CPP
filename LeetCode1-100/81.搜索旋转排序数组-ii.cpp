/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
//Binary  首先要转换问题，因为我们已经知道了传统二分查找  【AC】
//分类讨论 分成三段分析即可
//联系高中的二次函数的分类讨论
    bool BinaryDeep(vector<int>& nums,int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] == target)
                return true;
            // 能够准确完整的写出判断条件是不容易的。哪些地方该是等号。都是要注意的。
            if(nums[left] == nums[mid])
            {
                ++left;
                continue;
            }
            if(nums[left] < nums[mid])
            {
                if(nums[left] <= target && nums[mid] > target) //
                    right = mid - 1;
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        return BinaryDeep(nums,target);
    }
};
// @lc code=end

