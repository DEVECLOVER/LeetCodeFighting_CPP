/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
// 相同的思路，只不过我想的是用DFS实现，也得要两个结束判断条件，因为num1数组后面是0，不能只比较元素的大小
// 所以需要判断是否某个数组到达尽头
    //void DFS(vector<int>& nums1,int )
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m +n -1;
        int mlen = m - 1;
        int nlen = n - 1;
        while(mlen > -1 && nlen > -1)
        {
            if(nums1[mlen] > nums2[nlen])
            {
                nums1[index] = nums1[mlen];
                --index;
                --mlen;
            }
            else
            {
                nums1[index] = nums2[nlen];
                --index;
                --nlen;
            }
        }
        //这里不需要在判断mlen
        while(nlen > -1)
        {
                nums1[index] = nums2[nlen];
                --index;
                --nlen;
        }
    }
};
// @lc code=end

