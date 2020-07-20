/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
//自己还在想着如何利用回溯算法求解呢？都没有想到数学归纳法和动态规划
//对于这样的递推问题，应该首先想到数学归纳法的，即由前一个数推导后一个数
//了解后发现：真的有很多奇妙的结论  镜像排列啦  格雷公式啦  前人的研究结论啊，自己却一无所知
// 没想到是，第二遍再看这道题，还是同样的感喟，还是一样的想通过回溯算法，可悲可叹啊！
    vector<int> Cool(int n)
    {
        vector<int> result;
        result.push_back(0);
        for(int i = 0; i < n; i++){
            int e = 1 << i;                           //i - 1位结果前增加一位1
            for(int j = result.size() - 1; j >= 0; j--){    // 镜像排列
                result.push_back(e + result[j]);
            }
        }
        return result;
    }
    vector<int> grayCode(int n) {
        return Cool(n);
    }
};
// @lc code=end

