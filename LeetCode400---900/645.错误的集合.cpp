/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        //第一遍思路  错误的 [2 2]就已经无法正确运行了
        // vector<int> res;
        // for(int i = 0;i < nums.size();++i)
        // {
        //     if(nums[nums[i] - 1] > 0)
        //     {
        //         nums[nums[i] - 1] = -nums[nums[i] - 1];
        //     }
        //     else
        //     {
        //         res.push_back(nums[i]);
        //         res.push_back(i + 1);
        //         return res;
        //     }
        // }
        // return res;
        //分析上面为什么错误，上面只是找到了重复的数字，而没有寻找到缺失的
        //改正如下 【通过】
        // vector<int> res;
        // int len = nums.size();
        // for(int i = 0;i < len;++i)
        // {
        //     if(nums[abs(nums[i]) - 1] > 0)
        //         nums[abs(nums[i]) - 1] *= -1;
        //     else   
        //         res.push_back(abs(nums[i]));
        // }
        // for(int i = 0;i < len;++i)
        // {
        //     if(nums[i] > 0)//大于0对应的数正是缺失的数
        //     {
        //         res.push_back(i + 1);
        //         break;
        //     }
        // }
        // return res;
        //进一步减少遍历次数，通过求和的方式
        //因为求和的方式是很好找的，关键在于缺失的数字，因为数字连续，便可以求和
        int sum = 0;
        int len = nums.size();
        vector<int> res;
        for(int i = 0;i < len;++i)
        {
            sum += abs(nums[i]);
            if(nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
            else
                res.push_back(abs(nums[i]));
        }
        res.push_back(res[0] + (len * (len + 1) >> 1) - sum);
        return res;
    }
};
// @lc code=end

