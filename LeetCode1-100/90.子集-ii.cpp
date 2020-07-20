/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
// 就是按照回溯的思路写即可，因为是求出所有的子集，元素的个数是变动的。即是组合的扩展版
//[AC]
    void SetCore(vector<int>& nums,vector<int>& temp,vector<vector<int>>& result,int index,int start,int len)
    {
        if(index == len)
        {
            result.push_back(temp);
            return;
        }
        for(int i = start;i < nums.size();++i)
        {
            if(nums[i] == INT_MIN)
                continue;
            if(i > 0 && nums[i] == nums[i - 1])  // 两个剪枝条件
                continue;
            temp.push_back(nums[i]);
            int tempnum  = nums[i];
            nums[i] = INT_MIN;
            SetCore(nums,temp,result,index + 1,i + 1,len);
            nums[i] = tempnum;
            temp.pop_back();
        }
    }
    vector<vector<int>> GMT(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> result;
        for(int i = 0;i <= nums.size();++i)
        {
            SetCore(nums,temp,result,0,0,i);
        }
        return result;
    }
// 关键是如何快速的去重，看到题解中有通过位运算的。下次学习。
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        return GMT(nums);
    }
};
// @lc code=end

