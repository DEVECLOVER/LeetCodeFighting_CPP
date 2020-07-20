/*
 * @lc app=leetcode.cn id=447 lang=cpp
 *
 * [447] 回旋镖的数量
 */

// @lc code=start
class Solution {
public:
//思路差不多，但是这个代码优化了计算个数上，原本打算求出所有距离，然后 计算 n(n - 1)的
//如果按照上述思路，还得再进行一次循环，更加耗时
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int count = 0;
        int len = 0;
        map<int,int> hashmap;
        int size = points.size();
        for(int i = 0;i < size;++i)
        {
            hashmap.clear();
            for(int j = 0;j < size;++j)
            {
                if(i != j)
                {
                    len = pow(points[j][0] - points[i][0],2) + pow(points[j][1] - points[i][1],2);
                    ++hashmap[len];
                    // if(hashmap[len] > 1)
                    //     count += 2 * (hashmap[len] - 1); //这个转换很妙，边遍历边计算
                }
            }
            for(auto ele : hashmap)
            {
                if(ele.second > 1)
                {
                    count += ele.second * (ele.second - 1);
                }
            }
        }
        return count;
    }
};
// @lc code=end

