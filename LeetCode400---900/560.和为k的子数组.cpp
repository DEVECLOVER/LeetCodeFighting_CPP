/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution {
public:
//这个题目用滑动窗口也是不好使的，因为不能判断left移动的条件，结合前面的，总结那些题目适合滑动窗口，那些是哈希的
//自然想到利用前缀和，但是想着的还是先计算出前缀和，在遍历求取范围
//而不是边遍历，边计算，如何想到这样的思路呢？多积累
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hashmap;
        int sum = 0;
        hashmap[0] = 1;
        int count = 0;
        for(auto num : nums)
        {
            sum += num;
            if(hashmap.count(sum - k))
                //++count; 第一遍的思路，这是不对的，
                count += hashmap[sum - k];//应该是加上这个值出现的次数  吸取教训啊！
            ++hashmap[sum];
        }
        return count;
    }
};
// @lc code=end

