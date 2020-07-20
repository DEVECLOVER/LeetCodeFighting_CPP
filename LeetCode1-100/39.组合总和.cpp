/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
//我也是很佩服自己当时的一再坚持。
    vector<vector<int>> GMT(vector<int>& candidates,int target)
    {
        //自己分析之后的第一想法  但是终究不太可行 考虑的太复杂
        int len = candidates.size();
        vector<vector<int>> result;
        for(int i = 0;i < len;++i)
        {
            if((target % candidates[i]))
            {
                for(int j = 1;j <= (target / candidates[i]);++j)
                {
                    int gap = target - j * candidates[i];
                    if(find(candidates.begin(), candidates.end(), gap) != candidates.end())
                    {
                        vector<int> temp;
                        for(int k = 0;k < j;++k)
                        {
                            temp.push_back(candidates[i]);
                        }
                        temp.push_back(gap);
                        sort(temp.begin(),temp.end());
                        if(find(result.begin(),result.end(),temp) == result.end())
                        {
                            result.push_back(temp);
                        }
                    }
                }
            }
            else
            { 
                if(find(candidates.begin(),candidates.end(),1) != candidates.end() && candidates[i] != 1)
                {
                    for(int j = 1;j <= (target / candidates[i]);++j)
                    {
                        vector<int> temp;
                        int count = target - j * candidates[i];
                        for(int k = 0;k<count;++k)
                        {
                            temp.push_back(1);
                        }
                        for(int k = 0;k<j;++k)
                        {
                            temp.push_back(candidates[i]);
                        }
                        result.push_back(temp);
                    }
                }
                else
                {
                    vector<int> temp;
                    for(int j = 1;j <= (target / candidates[i]);++j)
                    {
                        temp.push_back(candidates[i]);
                    }
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
    
    void combinationSumCore(vector<int>& candidates, int index,int target,vector<int>& temp,vector<vector<int>>& result)
    {
        if(target == 0)
        {
            //sort(temp.begin(),temp.end());
            //if(find(result.begin(),result.end(),temp) == result.end())
            result.push_back(temp);
            return ;
        }
        for(int i = index;i < candidates.size() && (target - candidates[i] >= 0);++i)
        {
            temp.push_back(candidates[i]);
            combinationSumCore(candidates,i,target - candidates[i],temp,result);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        combinationSumCore(candidates,0,target,temp,result);
        return result;
    }
};
// @lc code=end

