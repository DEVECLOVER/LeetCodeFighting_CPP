/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class FenwickTree
{
    public:
        int len;
        vector<int> treearr;
        FenwickTree(int l):len(l)
        {
            for(int i = 0;i < l;++i)
                treearr.push_back(0);
        }
        //这个公式自我证明  联系快速求补码
        int lowbit(int num)
        {
            return num & (-num);
        }
        void update(int index,int num)
        {
            //注意是小于号
            while(index < len)
            {
                treearr[index] += num;
                index += lowbit(index);
            }
        }
        int Getsum(int index)
        {
            int res = 0;
            while(index)
            {
                res += treearr[index];
                index -= lowbit(index);
            }
            return res;
        }

};

class Solution {
public:
//【NAC】
     vector<int> UglyCode(vector<int>& nums)
    {
        int len = nums.size();
        if(len < 1)
            return vector<int>();
        vector<int> dp(len,0);
        //第一遍的想法  一维dp  但是 [2,0,1]  不对的
        //在这里所谓的dp 真的也就是暴力了  超时了
        for(int i = len  - 2;i >= 0;--i)
        {
            for(int j = i + 1; j < len;++j)
                if(nums[j] < nums[i])
                    ++dp[i];
                    //dp[i] = max(dp[i],dp[j] + 1);
        }
        return dp;
    }
//学习了树状数组，利用这个工具，很妙
//[AC]
    vector<int> Cool(vector<int>& nums)
    {
        vector<int> res;
        int len = nums.size();
        FenwickTree* mytree = new FenwickTree(len + 1);
        //利用这段代码不能将数据离散化
        // sort(nums.begin(),nums.end());
        // map<int,int> hashmap;
        // int index = 1;
        // for(auto num : nums)
        // {
        //     if(!hashmap.count(num))
        //         hashmap[num] = index++;
        // }

        unordered_map<int, int> hashmap;
        set<int> s;
        for (auto num : nums)
            s.insert(num);
        int index = 1;
        for (auto num : s)
        {
            hashmap[num] = index++;
        }
        for(int i = len - 1;i >= 0;--i)
        {
            int index = hashmap[nums[i]];
            mytree->update(index,1);
           res.push_back(mytree->Getsum(index - 1));
        }
        reverse(res.begin(),res.end());
        return res;
    }
    vector<int> countSmaller(vector<int>& nums) {
        return Cool(nums);
    }
};
// @lc code=end

