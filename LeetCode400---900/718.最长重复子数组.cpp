/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
//刚才还在想着如何使用hash，或者其他的容器，滑动窗口啥的
//已经全然忘记了动态规划，不应该啊
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int> dp(B.size()+1, 0);
        int result = 0;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = B.size()-1; j >= 0; --j) {
                dp[j+1] = A[i] == B[j] ? dp[j] + 1 : 0;
                result = max(result, dp[j+1]);
            }
        }
        return result;
    }
};
// @lc code=end

