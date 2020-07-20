/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
//思路是隐隐约约的，知道要一次遍历，但是涉及到编码的细节，头脑里不是很清晰，对自己要求也有点高了
//【AC】
    vector<vector<int>> Ergotic(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> res;
        int len = intervals.size();
        int index = 0;
        for(;index < len;++index)
        {
            if(newInterval[0] > intervals[index][1])
                res.push_back(intervals[index]);
            else
            {
                break;
            }
            
        }
        res.push_back(newInterval);
        for(;index < len;++index)
        {
            if(res.back()[1] < intervals[index][0])
                res.push_back(intervals[index]);
            else
            {
                res.back()[0] = min(res.back()[0],intervals[index][0]);
                res.back()[1] = max(res.back()[1],intervals[index][1]);
            }
        }
        return res;
    }
// 自己的第一想法：还是想要直接比较new 和  interval的左端元素的大小，这是肤浅的认识。
// 你看上面都是将右端与左端相比的。而不是同侧相比。这就是认识的不同。利用new的左端也就是上面的第一个循环。
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        return Ergotic(intervals,newInterval);
    }
};
// @lc code=end

