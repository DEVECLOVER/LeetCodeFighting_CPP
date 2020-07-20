/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
// 即是将三数之和进一步一般化。
//[AC]
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        unsigned int mingap = INT_MAX;
        int result;
        for(auto i = nums.begin();i < prev(nums.end(),2);++i)
        {
            auto j = next(i);
            auto k = prev(nums.end());
            while(j < k)
            {
                const int temp = (*i + *j + *k);
                const unsigned int gap = abs(temp - target);       
                if(gap < mingap)
                {
                    mingap = gap;
                    result = temp;
                }
                if(temp == target)
                {
                    return temp;
                } 
                else if(temp < target)
                {
                    ++j;
                }
                else
                {
                    --k;
                }
                
            }
        }
        return result;
    }
};
// @lc code=end

