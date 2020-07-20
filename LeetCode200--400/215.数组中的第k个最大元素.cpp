/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
    //快排即可
    int Partition(vector<int>& nums,int start,int end)
    {
        int left = start;
        int right = end;
        int num = nums[left];
        while(left < right)
        {
            while(left < right && nums[right] >= num)
                --right;
            nums[left] = nums[right];
            while(left < right && nums[left] <= num)
                ++left;
            nums[right] = nums[left];
        }
        nums[left] = num;
        return left;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        int start = 0;
        int end = len - 1;
        while(true)
        {
            int index = Partition(nums,start,end);
            if(index == len - k)
                return nums[index];
            if(index > len - k)
                end = index - 1;
            if(index < len - k)
                start = index + 1;
        }
    }
};
// @lc code=end

