/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
//利用在剑指offer中学到的方法，利用矩阵的转置的性质
//【AC】
    void Transpose(vector<int>& nums,int k)
    {
        int len = nums.size();
        k = k % len;
        if(k == 0)
            return;
        reverse(nums.begin(),nums.begin() + len - k);//是左闭右开区间的
        reverse(nums.begin() + len - k,nums.end());
        reverse(nums.begin(),nums.end());
    }
//还可以利用重复后截取的方法
//【AC】
    void Cool(vector<int>& nums,int k)
    {
        int len = nums.size();
        k = k % len;
        if(k == 0)
            return;
        nums.insert(nums.end(),nums.begin(),nums.end()); //这两种操作方式要熟练，不是用到了再过去查
        nums = vector<int>(nums.begin() + len - k,nums.begin() + ( len + len - k));//
    }
    void rotate(vector<int>& nums, int k) {
        //Transpose(nums,k);
        Cool(nums,k);
    }
};
// @lc code=end

