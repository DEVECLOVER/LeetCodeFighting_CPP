/*
 * @lc app=leetcode.cn id=1037 lang=cpp
 *
 * [1037] 有效的回旋镖
 */

// @lc code=start
class Solution {
public:
//面积为0
    bool isBoomerang(vector<vector<int>>& points) {
        //三角形性面积公式
        // int s = (points[0][0] * (points[1][1] - points[2][1])
        //         + points[1][0] * (points[2][1] - points[0][1])
        //         + points[2][0] * (points[0][1] - points[1][1]));
        // return s != 0;
        //斜率公式
        return (points[2][1] - points[0][1]) * (points[1][0] - points[0][0]) 
            != (points[1][1] - points[0][1]) * (points[2][0] - points[0][0]);
    }
};
// @lc code=end

