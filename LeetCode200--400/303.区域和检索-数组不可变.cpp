/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        int sum = 0;
        arr.push_back(sum);
        for(int i = 0 ;i < nums.size();++i)
        {
            sum += nums[i];
            arr.push_back(sum);
        }

    }
    //想法一 将和计算保存起来，直接调用即可
    //即利用前缀和
    int sumRange(int i, int j) {
        return arr[j + 1] - arr[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

