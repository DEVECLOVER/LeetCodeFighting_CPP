/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
class Solution {
public:
//想到滑动窗口，在里面存储最大值和最小值，都是很容易想到的，但是细节处还是要好好打磨的
//看了题解有联系到：二叉搜索树的，桶排序的，自己的认识还是差很多
//当然最先想到的还是暴力循环 [NAC] 暴力超时  40/41
    bool Violent(vector<int>& nums,int k,int t)
    {
        int len = nums.size();
        for(int i = 0;i < len;++i)
        {
            for(int j = 1;j <= k;++j)
            {
                if(i + j >= len)
                    break;
                if((nums[i+j] > 0 && nums[i] <= INT_MIN + nums[i + j]) 
                || (nums[i + j] < 0 && nums[i] > INT_MAX + nums[i + j]))
                    continue;
                if(abs(nums[i] - nums[i + j]) <= t)
                    return true;
            }
        }
        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        return Violent(nums,k,t);
    }
};
// @lc code=end

