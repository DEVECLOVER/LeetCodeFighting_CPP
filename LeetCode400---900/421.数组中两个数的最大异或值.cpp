/*
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */

// @lc code=start
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int N = nums.size();
        int res = 0;
        int mask = 0;
        for(int j = 31; j >= 0; j--) {
            mask = mask | (1 << j);
            unordered_set<int> dp;
            int temp = res | (1 << j);
            for(int i = 0; i < N; i++) {
                if (dp.find((nums[i] & mask)^temp) != dp.end()) {
                    res = temp;
                    break;
                } else {
                    // 其实由于2个数不轮什么顺序都可以，所以没有必要提前全部存好
                    dp.insert(nums[i] & mask);
                }
            }
        }
        return res;        
    }
};
// @lc code=end

