/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void Swap(int& p,int& q)
    {
        if(p == q)
        {
            return ;
        }
        int temp = p;
        p = q;
        q = temp;
    }
    void Reverse(vector<int>& nums,int left,int right)
    {
        while(left < right)
        {
            Swap(nums[left],nums[right]);
            ++left;
            --right;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size();
        for(int i = 0;i < len;++i)
        {
            for(int j = i + 1;j < len;++j)
            {
                Swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i = 0;i < len;++i)
        {
            Reverse(matrix[i],0,len - 1);
        }
    }
};
// @lc code=end

