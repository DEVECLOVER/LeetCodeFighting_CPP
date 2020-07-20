/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int Binary(vector<int>& nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        if(nums[0] < nums.back())
            return nums[0];
        while(left < right)  //注意这里也是小于，不含等于
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] > nums[right])
                left = mid + 1;
            else if(nums[mid] < nums[right])
                right = mid;
            else
            {
                --right; //这里是有很大的优化空间的，因为一旦出现相等情况，这个程序是每次减一处理，如果源数据中存在大量的相等情况，那么就是 O(n)了
                //或者遇到相等情况，直接采用遍历方式
            }
         }
         return nums[left];
    }
    int findMin(vector<int>& nums) {
        return Binary(nums);
    }
};
// @lc code=end

