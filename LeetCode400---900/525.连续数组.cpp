/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution {
public:
//想着如何使用滑动窗口，发现left始终无法右移
    int findMaxLength(vector<int>& nums) {
        map<int,int> hashmap;
        int len = nums.size();
        int count = 0;
        int maxlen = 0;
        hashmap[0] = -1;//初始条件 比如 0 1  情况下
        for(int i = 0;i < len;++i)
        {
            if(nums[i])
                ++count;
            else
                --count;
            if(hashmap.count(count))
                maxlen = max(maxlen,i - hashmap[count]);
            else
                hashmap[count] = i;
        }
        return maxlen;
    }
};
// @lc code=end

