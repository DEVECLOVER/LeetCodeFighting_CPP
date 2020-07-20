/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    void BackCore(vector<int>& nums,vector<int>& temp,vector<vector<int>>& result,int index)
    {
        if(index == nums.size())
        {
            result.push_back(temp);
            return ;
        }
        for(int i = 0;i < nums.size();++i)
        {
            if(nums[i] == INT_MIN)
                continue;
            if(i > 0 && nums[i] == nums[i - 1] && nums[i - 1] != INT_MIN)
                continue;
            temp.push_back(nums[i]);
            int tempnum = nums[i];
            nums[i] = INT_MIN;
            BackCore(nums,temp,result,index + 1);
            nums[i] = tempnum;
            temp.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> result;
        BackCore(nums,temp,result,0);
        return result;
    }
};
// @lc code=end

