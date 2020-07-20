/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @lc code=start
class Solution {
public:
//重要的是，分析问题
//一旦，有回答是一样的，那就可以理解为他们是同一种颜色，确保数量最少
//如果出现次数不一样，那就设为新的颜色
//问题就出在第一条结论，事实上，如果出现了 2 2 2 2 2 ，不能说只有三只兔子吧
//三只兔子，最大只能出现三个2，即 2 2 2 ，但是现在出现了 5个2，说明还有其他颜色的三只兔子，加上即可，逻辑也很简单
    int numRabbits(vector<int>& answers) {
        int res = 0;
        map<int,int> hashmap;
        for(auto num : answers)
            ++hashmap[num];
        for(auto num : hashmap)
        {
            int base = num.first + 1;
            if(num.first == 0)
                res += num.second;
            else if(num.second > base)
            {
                res += (num.second % base ? base * (num.second / base + 1) : num.second);
            }
            else    
                res += base;
        }
        return res;

    }
};
// @lc code=end

