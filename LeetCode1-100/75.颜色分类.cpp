/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
// 问题在于数组中只有三个数，如何快速排序呢？
// 有的是经过一次遍历，得到三个数分别的次数。
    void Swap(int& p,int& q)
    {
        if(p == q)
        {
            return;
        }
        int temp = p;
        p = q;
        q = temp;
    }
    void Cool(vector<int>& nums)
    {
        int index0 = 0;
        int index2 = nums.size() - 1;
        int index1 = 0;
        while(index1 <= index2)
        {
            if(nums[index1] == 0)
            {
                Swap(nums[index0++],nums[index1++]);
            }
            else if(nums[index1] == 2)
            {
                Swap(nums[index1],nums[index2--]);
            }
            else
            {
                ++index1;
            }
        }
    }
    void sortColors(vector<int>& nums) {
        return Cool(nums);
    }
};
// @lc code=end

