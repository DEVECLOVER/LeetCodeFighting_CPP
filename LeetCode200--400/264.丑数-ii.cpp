/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 7)
            return n;
        vector<int> res(n,0);
        res[0] = 1;
        int count2 = 0;
        int count3 = 0;
        int count5 = 0;
        for(int i = 1;i < n;++i)
        {
            //这就是递推关系
            res[i] = min(2 * res[count2],min(3 * res[count3],5 * res[count5]));
            if(res[i] == 2 * res[count2])
                ++count2;
            if(res[i] == 3 * res[count3])
                ++count3;
            if(res[i] == 5 * res[count5])
                ++count5;
        }
        return res[n - 1];

    }
};
// @lc code=end

