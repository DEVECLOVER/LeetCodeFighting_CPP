/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {
public:
//动态规划  后一个数的判断借用前一个的结果
//然后，使用前缀和  但是有个问题，如果是计算95 ~ 100，那么计算0-94是不划算的
//但是这种转换思路是很好的，学以致用
//自己并没有直接想到，32位的int，包含的质数是有限的，也就是32以内的质数，枚举出来即可
//还要一点，如何快速计算1的个数，位运算的掌握
    int countPrimeSetBits(int L, int R) {
        vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31};
        // map<int,int> hashmap;
        // for(auto num : primes)
        //     hashmap[num] = 1;
        int num = 0;
        //第一遍的写法，蠢不可耐，改变了 i 的值，怪不得始终死循环呢？
        // for(int i = L;i <= R;++i)
        // {
        //     int count = 0;
        //     while(i != 0)
        //     {
        //         i &= i - 1;
        //         ++count;
        //     }
        //     if(hashmap.count(count))
        //         ++num;
        // }
        //改正如下
        for(int i = L;i <= R;++i)
        {
            int count = 0;
            int tempnum = i;
            while(tempnum)
            {
                tempnum &= (tempnum - 1);
                ++count;
            }
            // if(hashmap.count(count))
            //     ++num;
            if(find(primes.begin(),primes.end(),count) != primes.end())
                ++num;
        }
        return num;

    }
};
// @lc code=end

