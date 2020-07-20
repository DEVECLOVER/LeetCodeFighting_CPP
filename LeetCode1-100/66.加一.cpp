/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
//【AC】  
    vector<int> GMT(vector<int>& digits)
    {
        int carrybit = 1;
        int len = digits.size();
        for(int i = len - 1;i >= 0;--i)
        {
            int temp = carrybit + digits[i];
            digits[i] = temp % 10;
            carrybit = temp / 10;
        }
        if(carrybit)
            digits.insert(digits.begin(),carrybit);
        return digits;
    }
    vector<int> plusOne(vector<int>& digits) {
        return GMT(digits);
    }
};
// @lc code=end

