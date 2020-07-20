/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
//即集合的所有真子集  2^n  
//非常棒  一次过哦  不错  开心  哈哈
    void SetCore(vector<int>& nums,vector<vector<int>>& result,vector<int>& temp,int index,int start,int len)
    {
        if(index == len)
        {
            result.push_back(temp);
            return;
        }
        for(int i = start;i < nums.size();++i)
        {
            temp.push_back(nums[i]);
            //关键点还是  递进的关系  如何推进和剪枝 
            // index 控制的是层数  
            // i 控制的是选择的数字
            //之前有只需要控制层数 ，选择的数字是固定的，而这里选择的数字也是变动的
            SetCore(nums,result,temp,index + 1,i + 1,len);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        for(int i = 0;i <= nums.size();++i)
        {
            SetCore(nums,result,temp,0,0,i);
        }
        return result;
    }
};
// @lc code=end

