/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
//利用内置函数，通过了 【AC】
    int GMT(int x)
    {
        if(x < 2)
            return x;
        return sqrt(x);
    }
//自己知道NewTon迭代法，但是自己直觉并不是这个方法，还是要思考

//还有二分查找 也应该想到的，对应于有序
// 两个较大数字相乘，溢出了
//[NAC]
    int Binary(int x)
    {
        if(x < 1)
            return x;
        if(x < 4)
            return 1;
        int right = x >> 1;
        int left = 2;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            long long obj = mid * mid;
            if(obj == x)
                return mid;
            else if(obj < x)
                left = mid + 1;
            else
            {
                right = mid - 1;
            }
        }
        return left - 1;
    }
//[AC]
    int BinaryDeeper(int x)
    {
        if(x < 1)
            return x;
        if(x < 4)
            return 1;
        int right = x >> 1;
        int left = 2;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(mid == x / mid)
                return mid;
            else if(mid < x / mid)
                left = mid + 1;
            else
            {
                right = mid - 1;
            }
            
        }
        return left - 1;
    }
    int mySqrt(int x) {
        //return GMT(x);
        //return Binary(x);
        return BinaryDeeper(x);
    }
};
// @lc code=end

