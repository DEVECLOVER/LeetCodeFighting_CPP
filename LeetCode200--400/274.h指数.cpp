/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H指数
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int count = 1;
        for(int index = citations.size() - 1;index >= 0;--index)
        {
            if(count > citations[index])
                break;
            ++count;
        }
        return count - 1;
    }
};
// @lc code=end

