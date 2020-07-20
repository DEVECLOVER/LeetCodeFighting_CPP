/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
//sort 即可 按照字典排序
//思路是很清晰的，但是如何高效简洁的实现，却是值得研究的，
//这是在网上看到的，C++ 的STL 用的确实很熟练
   string STL(vector<int>& nums)
   {
       if(all_of(nums.begin(),nums.end(),[](int x){return x== 0;})) //应对数组中全是0的元素 [0 0]
            return string("0");
        vector<string> str(nums.size());
        transform(nums.begin(),nums.end(),str.begin(),[](int x)
        {
            return to_string(x);
        });
        sort(str.begin(),str.end(),[](string& p,string& q)
        {
            return p + q > q + p;
        });
        return accumulate(str.begin(),str.end(),string());
   }
    string largestNumber(vector<int>& nums) {
        return STL(nums);
    }
};
// @lc code=end

