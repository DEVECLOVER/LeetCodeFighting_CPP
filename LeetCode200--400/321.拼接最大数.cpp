/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
public:
//编程问题的一大特点是分解问题  
//这个题目我的第一想法是寻找大的数，这样就可以减少搜索次数
//事实上，这个方法是人类的思维，不是计算机的，他的特长就是计算
//如何能把问题分解给计算机重复计算呢？
//已经有进步了，第二次看到这题已经想着计算机思维了
//那就是穷举，什么意思，因为从两个数组中取数，A中取 i 个，B中取 k- i个
//这就是计算机的计算方法。
//下面问题就转换为如何从数组中取 i个数字，且最大。
//这一点还是要加强的，没有立马想到单调栈，不应该啊！
//自己写一个将两个vector融合的程序，元素从大到小
    vector<int> maxKsequence(vector<int>& nums,int k)
    {
        int len = nums.size();
        if(len <= k)
            return nums;    
        vector<int> res;
        int popnum = len - k;//代表着最多只能pop这么多次
        for(auto num : nums)
        {
            //这里利用了短路原则，只有前面条件均满足，才会到执行popnum--
            //处处留心，都很有收获
            while(!res.empty() && num > res.back() && (popnum--) > 0)
                res.pop_back();
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res(k,0);
        for(int i = max(0,k - len2);i <= min(k,len1);++i)
        {
            vector<int> fir = maxKsequence(nums1,i);
            vector<int> sec = maxKsequence(nums2,k - i);
            vector<int> temp;
            // lexicographical_compare：比较两个序列的字典序大小
            auto iter1 = fir.begin(), iter2 = sec.begin();
            while (iter1 != fir.end() || iter2 != sec.end()){
                temp.push_back(lexicographical_compare(iter1, fir.end(), iter2, sec.end()) ? *iter2++ : *iter1++);
            }
            // 如果归并后的最大子序列大于目前已找到的最大子序列，则更新解
            res = lexicographical_compare(res.begin(), res.end(), temp.begin(), temp.end()) ? temp : res;
        }
        return res;
    }
};
// @lc code=end

