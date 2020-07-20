/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
//[AC]  正常的思路即可
    vector<vector<int>> Violent(vector<int>& nums,int target)
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int len = nums.size();
        for(int a = 0;a < len - 3;++a)
        {
            if(a > 0 && nums[a] == nums[a - 1])
                continue;
            for(int b = a + 1;b < len - 2;++b)
            {
                if((b > a + 1) && nums[b] == nums[b - 1])
                    continue;
                int left = b + 1;
                int right = len - 1;
                while(left < right)
                {
                    int sum = nums[a] + nums[b] + nums[left] + nums[right];
                    if(sum < target)
                    {
                        while(left < right && nums[left] == nums[++left]);
                    }
                    else if(sum > target)
                    {
                        while(left < right && nums[right] == nums[--right]);
                    }
                    else
                    {
                        res.push_back(vector<int>({nums[a],nums[b],nums[left],nums[right]}));
                        while(left < right && nums[left] == nums[++left]);
                        while(left < right && nums[right] == nums[--right]);
                    }
                    
                }
            }
        }
        return res;
    }
//应该要考虑到N数之和 
// 利用之前的NSum算法即可
//[AC]
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
                vector<int> cur(temp.begin(),temp.end());  //这一步也是关键的。
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
            if(nums[left] * n > obj || nums[len - 1] * n < obj) // 剪枝操作 
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
    vector<vector<int>> Cool(vector<int>& nums,int target) 
    {
        vector<vector<int>> res;
        vector<int> temp;
        int len = nums.size();
        sort(nums.begin(),nums.end());
        DFS_NSum(res,nums,temp,0,len,4,target);
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //return Violent(nums,target);
        return Cool(nums,target);

    }
};
// @lc code=end

