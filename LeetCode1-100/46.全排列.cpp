/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    void Swap(int& p,int& q)
    {
        if(p == q)
        {
            return ;
        }
        int temp = p;
        p = q;
        q = temp;
    }
//【AC】
    void PermuteCore(vector<int>& nums,vector<vector<int>>& result,int index,int len)
    {
        if(index == len)
        {
            result.push_back(nums);
        }
        //能想到交换 确实很妙  
        //但关键还是在于要掌握住回溯算法 就像manacher算法  了解即可，掌握住根本
        for(int i = index;i < len;++i)
        {
            Swap(nums[i],nums[index]);
            PermuteCore(nums,result,index + 1,len);
            Swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> Cool(vector<int>& nums) 
    {
        int len = nums.size();
        vector<vector<int>> result;
        PermuteCore(nums,result,0,len);
        return result;


    }
//关于回溯算法，关键就在于剪枝：如何高效的剪枝呢？下述方法中的改变值是屡试不爽的。
// 【AC】

    void BackCore(vector<int>& nums,vector<int>& temp,vector<vector<int>>& result,int index,int len)
    {
        if(index == len)
        {
            result.push_back(temp);
            return;
        }
        for(int i = 0;i < len;++i)
        {
            if(nums[i] == INT_MIN)
                continue;
            temp.push_back(nums[i]);
            int tempnum = nums[i];
            nums[i] = INT_MIN;
            BackCore(nums,temp,result,index + 1,len);
            nums[i] = tempnum;
            temp.pop_back();
        }
    }
   vector<vector<int>> GMT(vector<int>& nums) 
   {
        int len = nums.size();
        vector<int> temp;
        vector<vector<int>> result;
        BackCore(nums,temp,result,0,len);
        return result;
   }

    vector<vector<int>> permute(vector<int>& nums) {
        return Cool(nums);
        //return GMT(nums);
    }
};
// @lc code=end

