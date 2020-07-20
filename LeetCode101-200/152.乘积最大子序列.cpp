/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */

// @lc code=start
class Solution {
public:
//【NAC】
    int FirstCode(vector<int>& nums)
    {
        int res = INT_MIN;
        int maxnum = 1;
        int minnum = 1;
        int len = nums.size();
        for(int i = 0;i < len;++i)
        {
            if(nums[i] >= 0)
            {
                maxnum = max(maxnum * nums[i],nums[i]);
                minnum = min(minnum * nums[i],nums[i]);
            }
            else
            {
                //运行数组[-4 -3 -2]的结果为 72
                //折磨了自己五分钟，没发现什么问题
                //实际上有天大的漏洞啊，maxnum计算完后，接着就给输入了
                maxnum = max(minnum * nums[i],nums[i]);
                minnum = min(maxnum * nums[i],nums[i]);

            }
            res = max(res,maxnum);
        }
        return res;
    }
    int DpCore(vector<int>& nums)
    {
        int res = INT_MIN;
        int maxnum = 1;
        int minnum = 1;
        int len = nums.size();
        for(int i = 0;i < len;++i)
        {
            if(nums[i] >= 0)
            {
                maxnum = max(maxnum * nums[i],nums[i]);
                minnum = min(minnum * nums[i],nums[i]);
            }
            else
            {
                //使用临时变量保存一下之前的值即可
				int tempmax = maxnum;
				int tempmin = minnum;
				maxnum = max(tempmin * nums[i], nums[i]);
				minnum = min(tempmax * nums[i], nums[i]);
            }
            res = max(res,maxnum);
        }
        return res;
    }
    int maxProduct(vector<int>& nums) {
        return DpCore(nums);
    }
};
// @lc code=end

