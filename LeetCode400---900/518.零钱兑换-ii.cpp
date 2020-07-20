/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
class Solution {
public:
//超时  当钱数太大时  迭代过多
    void Core(vector<int>& coins,int& count,int amount,int index)
    {
        if(amount == 0)
        {
            ++count;
            return;
        }
        for(int i = index;i < coins.size();++i)
        {
            if(amount < coins[i])
            {
                break;
            }
            Core(coins,count,amount - coins[i],i);
        }

    }
    int change(int amount, vector<int>& coins) {
        //DP算法
        

        /*
        int count = 0;
        sort(coins.begin(),coins.end());
        Core(coins,count,amount,0);
        return count;
        */
    }
};
// @lc code=end

