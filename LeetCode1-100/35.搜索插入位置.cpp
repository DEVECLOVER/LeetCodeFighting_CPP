/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
//二分法即可
//结果 二分法比遍历还慢呢？
    int SearchCore(vector<int>& nums,int target)
    {
        if(target < nums[0])
            return 0;
        else if(target > nums.back())
            return nums.size();
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(nums[mid] == target)
                return mid;
            // else if(nums[mid] < target && nums[mid + 1] > target)
            //     return mid + 1;
            // else if(nums[mid] > target && nums[mid - 1] < target)
            //     return mid;
            else if(nums[mid] > target)
                right = mid - 1;
            else if(nums[mid] < target)
                left = mid + 1;
        }
        //return -1;
        return left;
    }
    int Brute(vector<int>& nums,int target)
    {
        if(target < nums[0])
            return 0;
        else if(target > nums.back())
            return nums.size();
        int len = nums.size();
        for(int i  = 0;i < len;++i)
        {
            if(nums[i] == target)
                return i;
            else if((i + 1) < len && target > nums[i] && target < nums[i + 1])
                return i + 1;
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
         //return Brute(nums,target);
        return SearchCore(nums,target);
    }
};
// @lc code=end

