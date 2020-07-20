/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
//vector中的元素通过二项式定理给出，这样就是常数空间了
//或者利用递推关系，后一个仅与前一个有关，所以就是 k 空间复杂度
// 【AC】
    vector<int> Kth(int num)
    {
        if(num < 1)
            return {1};
        if(num == 1)
            return {1,1};
        vector<int> pre = {1,1};
        int count = 1;
        while(count++ < num)
        {
            vector<int> temp;
            temp.push_back(1);
            int len = pre.size();
            for(int i = 0;i < len - 1;++i)
            {
                temp.push_back(pre[i] + pre[i + 1]);
            }
            temp.push_back(1);
            pre = temp;
        }
        return pre;
     }
//看了大家的题解，还有更妙的解法，
    vector<int> Kth2(int num)
    {
        vector<int> res;
        for(int i = 0;i <= num;++i)
        {
            res.push_back(1);
            for(int j = i;j > 1;--j)
            {
                res[j - 1] = res[j - 1] + res[j - 2];
            }
        }
        return res;
    }
    vector<int> getRow(int rowIndex) {
        //return Kth(rowIndex);
        return Kth2(rowIndex);
    }
};
// @lc code=end

