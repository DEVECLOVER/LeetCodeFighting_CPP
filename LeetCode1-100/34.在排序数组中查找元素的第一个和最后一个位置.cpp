/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
//特点在于：将查询左右两侧改为只查左侧。int到double
//[AC]
    int GetIndex(vector<int>& nums, double target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (left + right) >> 1;
            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
    vector<int> GMT(vector<int>& nums, int target)
    {
        vector<int> result(2,-1);
        int len = nums.size();
        if(len < 1)
        {
            return result;
        }
        if(target < nums[0] || target > nums[len - 1])
        {
            return result;
        }
        int left = GetIndex(nums,target - 0.5);
        int right = GetIndex(nums,target + 0.5);
        if(left != right)
        {
            result.clear();
            result.push_back(left);
            result.push_back(right - 1);
            return result;
        }
        return result;
    }
// 传统的做法就是定位左侧和右侧。二分查找
    vector<int> searchRange(vector<int>& nums, int target) {
        return GMT(nums,target);
    }
};
// @lc code=end

