/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    void ComCore(vector<vector<int>>& result,vector<int>& temp,int index,const int& num,const int& size)
    {
        if(temp.size() == size)
        {
            result.push_back(temp);
            return;
        }
        for(int i = index;i <= num;++i)
        {
            temp.push_back(i);
            ComCore(result,temp,i + 1,num,size);
            temp.pop_back();
        }
    }
    vector<vector<int>> GMT(int n, int k) 
    {
        vector<vector<int>> result;
        vector<int> temp;
        ComCore(result,temp,1,n,k);
        return result;
    }
    vector<vector<int>> combine(int n, int k) {
        return GMT(n,k);
    }
};
// @lc code=end

