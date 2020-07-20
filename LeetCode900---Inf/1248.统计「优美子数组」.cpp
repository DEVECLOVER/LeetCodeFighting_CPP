/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 */

// @lc code=start
class Solution {
public:
//Sliding window  
//看到题目就联想起，统计包含子串的子串个数了
//这是第一想法，思考的不全面，看了测试用例
//发现了问题所在 [2 2 1 2 2] k = 1, 便出现问题了
//【NAC】
    int GMT(vector<int>& nums,int k)
    {
        int count = 0;
        int left = 0;
        int res = 0;
        for(auto num : nums)
        {
            if(num & 1)
            {
                ++count;
                while(count == k)
                {
                    ++res;
                    if(nums[left] & 1)
                        --count;
                    ++left;
                }
            }
        }
        return res;
    }
//如何改进呢？通过上面分析，个数应该是左右偶数个数的组合
//哈哈，经典死循环，如果不是去VS调试，打死也找不到bug啊
//[NAC]
    int GMT2(vector<int>& nums,int k)
    {
        int res = 0;
        int count = 0;
        int left = 0;
        int right = 0;
        int len = nums.size();
        while(right < len)
        {
            if(nums[right] & 1)
            {
                ++count;
                if(count == k)
                {
                    int tempright = 0;
                    while(right + 1 < len && (nums[++right] & 1) == 0)
                    {
                        ++tempright;
                    }
                    int templeft = 0;
                    while ((nums[left] & 1) == 0)
                    {
                        ++templeft;
                        ++left;
                    }
                    res += (templeft + 1) * (tempright + 1);
                    ++left;
                    --count;
                    continue;
                }
            }
            ++right;
        }
        return res;
    }
//吸取教训，如何一次性写出AC的代码
// [AC]
    int GMT3(vector<int>& nums,int k)
    {
        int res = 0;
        int count = 0;
        int left = 0;
        int right = 0;
        int len = nums.size();
        while(right < len)
        {
            if(nums[right++] & 1)
            {
                ++count;
                if(count == k)
                {
                    int tempright = 0;
                    while(right < len && (nums[right] & 1) == 0)
                    {
                        ++tempright;
                        ++right;
                    }
                    int templeft = 0;
                    while ((nums[left] & 1) == 0)
                    {
                        ++templeft;
                        ++left;
                    }
                    res += (templeft + 1) * (tempright + 1);
                    ++left;
                    --count;
                }
            }
        }
        return res;
    }
//上述的都是一般性思维方式，看了题解还有更妙的
//很厉害,这是对上述思想的深刻把握，然后分析总结得到的
// 【AC】
    int Cool(vector<int>& nums,int k)
    {
        int res = 0;
        unordered_map<int,int> hashmap;
        hashmap[0] = 1;
        int sum = 0;
        for(auto num : nums)
        {
            sum += (num & 1);
            ++hashmap[sum];
            if(sum >= k)
                res += hashmap[sum - k];
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        //return GMT(nums,k);
        //return GMT3(nums,k);
        return Cool(nums,k);
    }
};
// @lc code=end

