/*
 * @lc app=leetcode.cn id=991 lang=cpp
 *
 * [991] 坏了的计算器
 */

// @lc code=start
class Solution {
public:
//最暴力的解法，回溯法，每次只有两种选择  但是问题在于用回溯法如何得到最优解呢？不容易的
//在选择是可以剪枝，发现 倍乘后大于object，便舍弃
//方法二，优化思路，提炼规律，逆向思维
//为什么？道理何在，目的在于逼近
    void BackCore(const int Y,int& count,int num,int index,const int sum)
    {
        if(index > sum)
            return ;
        if(num == Y)
        {
            count = min(count,index);
        }
        if(num <= (Y >> 1) || 2 * (num - 1) < Y)
            BackCore(Y,count,num << 1,index + 1,sum);
        else
            BackCore(Y,count,num - 1,index + 1,sum);
    }
    int brokenCalc(int X, int Y) {
        int count = 0;
        while(Y > X)
        {
            ++count;
            if(Y & 1)
                ++Y;
            else
                Y >>= 1;
        }
        return count + X - Y;


        // int count = INT_MAX;
        // BackCore(Y,count,X,0,X+Y);
        // return count;
    }
};
// @lc code=end

