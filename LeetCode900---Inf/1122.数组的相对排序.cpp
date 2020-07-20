/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
//第一想法还是，map 
//看了题解，有人想到了，交换，也是可以的
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // int index = 0;
        // for(auto num2 : arr2)
        // {
        //     for(auto& num1 : arr1) //必须用引用
        //     {
        //         if(num1 == num2)
        //             swap(arr1[index++],num1);
        //     }
        // }
        // sort(arr1.begin() + index,arr1.end());
        // return arr1;
        //map统计次数
        vector<int> res;
        map<int,int> hashmap;
        for(auto num : arr1)
            ++hashmap[num];
        for(auto num : arr2)
        {
            while(hashmap[num]--)
            {
                res.push_back(num);
            }
            hashmap.erase(num);
        }
        for(auto num : hashmap)
        {
            while(num.second--)
            {
                res.push_back(num.first);
            }
        }
        return res;
    }
};
// @lc code=end

