/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H指数 II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0;
        int len = citations.size();
        int right = len - 1;
        if(len < 1 || citations[right] == 0)
            return false;
        while(left < right)
        {
            int pivot = left + ((right- left) >> 1);
            if(citations[pivot] < len - pivot)
                left = pivot + 1;
            else
                right = pivot;
        }
        return len - left;
    }
};
// @lc code=end

