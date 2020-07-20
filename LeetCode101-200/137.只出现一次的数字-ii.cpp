/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unsigned int checker = 1;
        int result = 0;
        while(checker)
        {
            int temp = 0;
            for(int i = 0;i < nums.size();++i)
            {
                if(nums[i] & checker)
                {
                    ++temp;
                }
            }
            if(temp % 3 != 0)
            {
                result |= checker;
            }
            checker <<= 1;
        }
        return result;

    }
};
// @lc code=end

