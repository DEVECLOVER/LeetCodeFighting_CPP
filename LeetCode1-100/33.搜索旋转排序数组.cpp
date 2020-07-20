/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
//[AC]
    int Binary(vector<int>& nums,int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] == target)
                return mid;
            if(nums[left] <= nums[mid])
            {
                if(nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
    int GMT(vector<int>& nums,int target)
    {
        int right = nums.size() - 1;
        int left = 0;
        //此处不是 < ，也是经过分析的。
        while(left <= right)
        {
            int mid = (left + right) >> 1;
            if(nums[mid] == target)
            {
                return mid;
            }
            //注意等号的问题，此处的等号与内部的等号是相关联的。
            //如果条件满足，说明数组的前半段是有序的
            if(nums[left] <= nums[mid])
            {
                if(nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if(nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
         }
        return -1;
    }
//剑指offer中进一步分析，如何找到旋转点呢？
//同样是查找类的问题，但是两者是不一样的。查找旋转点，旋转点是与两边值相关联的。要通过与两边比较来断定是不是旋转点。
//如果是单一的查找，只需要比较值是否相等即可
    int search(vector<int>& nums, int target) {
        return Binary(nums,target);
    }
};
// @lc code=end

