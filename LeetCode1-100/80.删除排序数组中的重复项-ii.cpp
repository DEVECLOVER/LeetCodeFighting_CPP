/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
// 【AC】  下面的代码是一般性思维方法，不是很简洁。
// 可以拓展，保留的次数时可变的。 
    int GMT(vector<int>& nums,const int k)
    {
        if(nums.size() < 3)
            return nums.size();
        int len = nums.size();
        int index = 0;
        int count = 1;
        for(int i = 1;i < len;++i)
        {
            if(nums[i] != nums[i - 1])
            {
                nums[++index] = nums[i];
                count = 1;
            }
            else
            {
                ++count;
                if(count <= k)
                    nums[++index] = nums[i];
                else
                    continue;
            }
            
        }
        return index + 1;
    }
// 这个是一定要作为反面典型的。自己有没有真正的理解知识点。
    int Cool(vector<int>& nums,const int& k)
    {
        int index = k;
        int len = nums.size();
        for(int i = k;i < len;++i)
        {
            if(nums[i] != nums[i - k])  // 错误至极  应为nums[i] != nums[index - k]
            {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
    int removeDuplicates(vector<int>& nums) {
        return GMT(nums,2);
        //return Cool(nums,2);
    }
};
// @lc code=end

