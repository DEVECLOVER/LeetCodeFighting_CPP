/*
 * @lc app=leetcode.cn id=575 lang=cpp
 *
 * [575] 分糖果
 */

// @lc code=start
class Solution {
public:
//哈哈，一遍分析一遍过
//深度思考，怎么想的呢？刚开始，我哪一样都拿一个，这是我能拿到的最大种类数，但是还有数量的限制
//如果种类数不大于总数的一半，那么直接输出即可
//如果大于一半呢，那就得拿出一点给弟弟，分析可知，只能拿到总数一半的种类数了，因为不论拿出哪个，
//留在你手里的种类数都是总数的一半的
    int distributeCandies(vector<int>& candies) {
        map<int,int> hashmap;
        for(auto sweet : candies)
            ++hashmap[sweet];
        // int half = candies.size() >> 1;
        // return hashmap.size() > (candies.size() >> 1) ? half : hashmap.size();
        //得意忘形到已经忘记了 min函数了  居然写出上面那样丑陋的代码
        return min(hashmap.size(),candies.size() >> 1);
    }
};
// @lc code=end

