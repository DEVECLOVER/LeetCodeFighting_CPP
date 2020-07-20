/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
//这个题目还是简化了的，不存在重复元素，如果加上这个条件，那么分类就又要多加一层了
//和剑指offer的一样的思路
//经过旋转后，数组变为两个排序的数组，最小元素即是分界线
//【AC】
    int GMT(vector<int>& nums)
    {
        int len = nums.size();
        if(nums[0] <= nums.back())
            return nums[0];
        int left = 0;
        int right = len - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(mid - 1 >= 0 && nums[mid - 1] > nums[mid])
                return nums[mid];
            if(mid + 1 < len && nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if(nums[mid] > nums[left])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
//代码比上述的短，但是运行时间比上述长。
//左右不对称的原因
    int Binary(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        if(nums[0] <= nums.back())
            return nums[0];
        while(left < right)  //注意这里是小于号  不含等于
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] < nums[right])
                right = mid;
            else
            {
                left = mid + 1;
            }
        }
        return nums[left];
    }
    int findMin(vector<int>& nums) {
        //return GMT(nums);
        return Binary(nums);
    }
};
// @lc code=end

