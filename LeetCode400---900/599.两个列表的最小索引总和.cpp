/*
 * @lc app=leetcode.cn id=599 lang=cpp
 *
 * [599] 两个列表的最小索引总和
 */

// @lc code=start
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> hashmap;
        int minindex = 2000;//最开始设置为1000，出错了，切记
        int len1 = list1.size();
        int len2 = list2.size();
        vector<string> res;
        //正常思路  熟练为止
        for(int i = 0;i < len1;++i)
        {
            hashmap[list1[i]] = i; 
        }
        for(int i = 0;i < len2;++i)
        {
            if(hashmap.count(list2[i]))
            {
                int sum = i + hashmap[list2[i]];
                if(sum < minindex)
                {
                    res.clear();
                    res.push_back(list2[i]);
                    minindex = sum;
                }
                else if(sum == minindex)
                    res.push_back(list2[i]);
            }
        }
        return res;

    }
};
// @lc code=end

