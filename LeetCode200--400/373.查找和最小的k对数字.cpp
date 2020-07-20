/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

// @lc code=start
class Solution {
public:
//第一想法是利用递归 后来发现自己理解错了  但还是很有借鉴意义的
    void PairCore(vector<int>& nums1,vector<int>& nums2,int index1,int index2, int count,const int& k,vector<vector<int>>& res)
    {
        if(count > k)
            return;
        if(index1 >= nums1.size() - 1 && index2 >= nums2.size() - 1)
        {
            res.push_back({nums1[index1],nums2[index2]});
            return;
        }
        res.push_back({nums1[index1],nums2[index2]});
        if(index1 + 1 < nums1.size() && index2 + 1 < nums2.size())
        {
            nums1[index1] + nums2[index2 + 1] < nums1[index1 + 1] + nums2[index2] ? 
            PairCore(nums1,nums2,index1,index2 + 1,count + 1,k,res) : PairCore(nums1,nums2,index1 + 1,index2,count + 1,k,res);
        }
        else if(index1 + 1 >= nums1.size())
        {
            PairCore(nums1,nums2,index1,index2 + 1,count + 1,k,res);
        }
        else if(index2 + 1 >= nums2.size())
        {
            PairCore(nums1,nums2,index1 + 1,index2,count + 1,k,res);
        }
    }
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if(nums1.empty() || nums2.empty())
            return res;
        // PairCore(nums1,nums2,0,0,1,k,res);
        // return res;

        for(int i = 0;i < nums1.size();++i)
        {
            for(int j = 0;j < nums2.size();++j)
            {
                res.push_back({nums1[i],nums2[j]});
            }
        }
        //用与不用引用，差距还是有的
        sort(res.begin(),res.end(),[](vector<int>& p,vector<int>& q)
        {
            return ((p[0] + p[1]) < (q[0] +  q[1]));
        }
        );
        //如果直接使用  res.begin(),res.begin() + k  会超时 
        //return (res.size() > k ? vector<vector<int>>(res.begin(),res.begin() + k) : res);
        if(res.size() <= k)
            return res;
        vector<vector<int>> result;
        for(int i = 0;i < k;++i)
            result.push_back(res[i]);
        return result;
    }
};
// @lc code=end

