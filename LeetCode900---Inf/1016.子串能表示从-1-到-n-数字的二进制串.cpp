/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */

// @lc code=start
class Solution {
public:
//怎么想会编出这道题呢？作者当初想用什么方法呢？考察什么知识点呢？
//自己借鉴这种思路，可以编出什么样的题呢？
//Rabin-Karp算法+递归   闻所未闻
//最直觉的做法，获得1-N的各个数字的二进制位，然后判断是不是子串即可
//真的学习的是：字符串的一些操作，如何去掉开头的0，如何判断子串   s.find 可以用
    int bitLen(int n) {
        int res = 0;
        while (n > 0) {
            ++res;
            n >>= 1;
        }
        return max(res, 1);
    }
    bool queryString(string S, int N) {
        if (N == 0) return true;
        int k = bitLen(N);
        if (k > S.size()) return false;
        long h = 0;
        for (int i = 0; i < k; ++i) {
            h <<= 1;
            h |= S[i] - '0';
        }
        if (h == N) return queryString(S, N - 1);
        for (int i = k; i < S.size(); ++i) {
            h <<= 1;
            h |= S[i] - '0';
            h &= ~((S[i - k] - '0') << k);
            if (h == N) return queryString(S, N - 1);
        }
        return false;
    }
};
// @lc code=end

