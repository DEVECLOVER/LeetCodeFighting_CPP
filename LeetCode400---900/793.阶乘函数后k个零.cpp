/*
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后K个零
 */

// @lc code=start
class Solution {
public:
//自己虽然知道产生0的条件，但是分析的还不是清楚
//好好思考
    int GetIndex(int k)
    {
        int count = 0;
        int num = 5;
        while(count < k - 1)
        {
            count += num / 5;
            
        }
    }
    int preimageSizeFZF(int K) {
        if( K == 0)
            return 5;
        int count = 0;
        while(K >= 5)
        {
            count += K / 5;
            K /= 5;
        }
        return count;
    }
};
// @lc code=end

