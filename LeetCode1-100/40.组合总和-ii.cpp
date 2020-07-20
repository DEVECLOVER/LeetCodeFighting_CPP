/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    void combinationSumCore(vector<int>& candidates,int index,int target,vector<int>& temp,vector<vector<int>>& result)
    {
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }
        //如何表达只使用一次，还可以改值。
        for(int i = index;i < candidates.size() && target - candidates[i] >= 0;++i)
        {
            if(i > index && candidates[i] == candidates[ i -1]) continue;
            temp.push_back(candidates[i]);
            combinationSumCore(candidates,i + 1,target - candidates[i],temp,result);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        combinationSumCore(candidates,0,target,temp,result);
        return result;
    }
};
// @lc code=end

