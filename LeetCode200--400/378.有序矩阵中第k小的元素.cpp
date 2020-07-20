/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第K小的元素
 */

// @lc code=start
class Solution {
public:
    int BinarySearch(vector<int>& nums,int target)
    {
        int left = 0;
        int right = nums.size();
        while(left < right)
        {
            int index = left + ((right - left) >> 1);
            if(nums[index] > target)
                right = index;
            else
                left = index + 1;
        }
        return left; 
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = matrix[0][0];
        int high = matrix.back().back();
        while(low < high)
        {
            int count = 0;
            int mid = low + ((high - low) >> 1);
            for(int i = 0;i < matrix.size();++i)
            {
                count += BinarySearch(matrix[i],mid);
            }
            if(count < k)
                low = mid + 1;
            else 
                high = mid;
        }
        return low;
    }
};
// @lc code=end

