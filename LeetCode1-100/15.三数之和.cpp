/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
// 这样的代码就说明自己当时的心情是比较乱的，纯粹是为了多刷题，充面子。
    vector<vector<int>> UglyCode(vector<int>& nums)
    {
        vector<vector<int>> result;
        int len = nums.size();
        if(len < 3)
        {
            return result;
        }
        const int target = 0;
        sort(nums.begin(),nums.end());
        auto last = nums.end();
        for (auto i = nums.begin(); i < last-2; ++i) 
        {
            auto j = i+1;
            if (i > nums.begin() && *i == *(i-1)) continue;
            auto k = last-1;
            while (j < k) 
            {
                if (*i + *j + *k < target) 
                {
                    ++j;
                    while(*j == *(j - 1) && j < k) ++j;
                } 
                else if (*i + *j + *k > target) 
                {
                    --k;
                    while(*k == *(k + 1) && j < k) --k;
                } 
                else 
                {
                    result.push_back({ *i, *j, *k });
                    ++j;
                    --k;
                    while(*j == *(j - 1) && *k == *(k + 1) && j < k) ++j;
                }
            }
        }
        return result;
    }
//[AC]
// 自然想到实现N——Sum
// 如何实现N呢？转化为二维的吗。
    vector<vector<int>> GMT(vector<int>& nums)
    {
        vector<vector<int>> result;
        int len = nums.size();
        if(len < 3)
        {
            return result;
        }
        const int target = 0;
        sort(nums.begin(),nums.end());
        for (int i = 0;i < len - 2; ++i) 
        {
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = len - 1;
            while (j < k) 
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target) 
                {
                    ++j;
                    while(j < k && nums[j] == nums[j - 1]) 
                        ++j;
                } 
                else if (sum > target) 
                {
                    --k;
                    while(j < k && nums[k] == nums[k + 1]) 
                        --k;
                } 
                else 
                {
                    result.push_back({nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                    while(j < k && nums[j] == nums[j - 1]) 
                        ++j;
                }
            }
        }
        return result;
    }
    void Binary(vector<vector<int>>& res,vector<int>& nums,vector<int> temp,int pos,const int obj)
    {
        int left = pos;
        int right = nums.size() - 1;
        while(left < right)
        {
            int sum = nums[left] + nums[right];
            if(sum > obj)
                --right;
            else if(sum < obj)
                ++left;
            else
            {
                vector<int> cur(temp.begin(),temp.end());
                cur.push_back(nums[left]);
                cur.push_back(nums[right]);
                res.push_back(cur);
                while(left < right && nums[left] == nums[left + 1])
                    ++left;
                while(left < right && nums[right] == nums[right - 1])
                    --right;
                ++left;
                --right;
            }
        }
    }
    void DFS_NSum(vector<vector<int>>& res,vector<int>& nums,vector<int> temp,int pos,const int len ,int n,const int obj)
    {
        if(n == 2)
        {
            Binary(res,nums,temp,pos,obj);
            return;
        }
        int left = pos;
        while(left < len - n + 1)
        {
            if(nums[left] * n > obj || nums[len - 1] * n < obj)
                break;
            if(left > pos && nums[left] == nums[left - 1]) // 这里不是while，要想清楚,这里的判断条件不能改为nums[left] == nums[left + 1]
            {
                ++left;
                continue;
            }
            temp.push_back(nums[left]);
            DFS_NSum(res,nums,temp,left + 1,len,n - 1,obj - nums[left]);
            temp.pop_back();
            ++left;
        }
    }
    vector<vector<int>> Cool(vector<int>& nums) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        DFS_NSum(res,nums,temp,0,len,3,0);
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        //return UglyCode(nums);
        //return GMT(nums);
        return Cool(nums);
    }
};
// @lc code=end

