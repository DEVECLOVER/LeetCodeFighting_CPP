/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
//我也想到了初始给每个学生一个，然后遍历相邻的条件，但是分析知道这是有问题的
//当时自己举的例子是 [3 2 1 0 1 2 3]
//这正如自己之前做距离元素0的距离那样，想到了Dp，但是如何遍历，是采取左上和右下的两次遍历
//这次在这里呢？也是正序和逆序的两次遍历，真的很妙，过程中体现出来自己如何分析问题的，值得好好总结
//看了题解，你会发现大家的第一想法都是这样的，但都是困在代码的实现上，我不禁回想起第一次见到归并排序，感觉好神奇啊，
//这么写怎么就可以了呢？
//[AC]  想想暴力破解呢？
    int Dp(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> direct(len,1);
        vector<int> reverse(len,1);
        for(int i = 1;i < len;++i)
        {
            if(nums[i] > nums[i - 1])
                direct[i] = direct[i - 1] + 1;
        }
        reverse.back() = direct.back();
        int res = direct.back();
        for(int i = len  - 2;i >= 0;--i)
        {
            if(nums[i] > nums[i + 1])
                reverse[i] = reverse[i + 1] + 1;
            res += max(reverse[i],direct[i]);
        }
        return res;

    }
    int candy(vector<int>& ratings) {
        return Dp(ratings);
    }
};
// @lc code=end

