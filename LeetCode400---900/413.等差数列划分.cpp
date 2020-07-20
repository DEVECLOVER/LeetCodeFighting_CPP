/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @lc code=start
class Solution {
public:
//第一想法，利用哈希表存储每个元素与前一个元素的差值
//但事实上是不需要的，边遍历，边计算就好了，不需要回溯（回头计算是多余的）
//非常巧妙的方法  [AC]
     int Fun(vector<int>& A)
     {
        int n = 0;
        int pre = 0;
        int last = 0;
        int len = A.size();
        int sum = 0;
        for(int i = 1; i < len - 1;++i)
        {
            pre = A[i] - A[i - 1];
            last = A[i + 1] - A[i];
            if(pre == last)
            {
                if(n)
                    ++n;
                else
                    n = 3;
            }
            else
            {
                if(n >= 3)
                    sum += (((n - 1) * (n - 2)) >> 1);  
                n = 0;
            }
        }
        //这个公式对应的 个数为 n 的等差数列，包含子等差数列的个数，稍加分析可知为：(n - 2) + …… + 1
        // n- 2 是因为 至少三个元素
        if(n > 2)
            sum += (((n - 1) * (n - 2)) >> 1);
        return sum;
     }
//现在思考问题已经很少往暴力方面想了，其实刚开始想想还是可以的，给自己一点思路
//暴力法也是自己优化的开始  其实这是很好思考的 [AC]
    int Violent(vector<int>& A)
    {
        int count = 0;
        int len = A.size();
        for(int i = 0;i < len - 2;++i)
        {
            int step = A[i + 1] - A[i];
            for(int j = i + 2;j < len;++j)
            {
                if(A[j] - A[j - 1] == step)
                    ++count;
                else    
                    break; //因为数组要求连续，一旦中断，便抛弃了，重新开始了，后面无需再算了
            }
        }
        return count;
    }
//那么如何将上述暴力算法优化呢  [AC]
//自顶向下
    int DFS(vector<int>& A,int index,int& sum)
    {
        if(index < 2)
            return 0;
        int count = 0;
        if(A[index] - A[index - 1] == A[index - 1] - A[index - 2])
        {
            count = 1 + DFS(A,index - 1,sum);
            sum += count;        
        }
        else
            DFS(A,index - 1,sum);
            //第一次给写成了 count = DFS(A,index - 1,sum);//然而这里不需要接受返回值，为什么呢？
            //是的，这里不需要的，真的，每一步都要细细思考
            //因为这里 count 计算的是 以index结尾的等差数列的个数，当不满足上面等式时，他的值为零，不需要接受的，直接返回即可
            //每一步都要好好思考啊！！！
        return count;
    }
//有了上面的DFS思路，动态规划便呼之欲出了
//自底向上  [AC] 
    int DPCore(vector<int>& A)
    {
        int len = A.size();
        int dp = 0;
        int sum = 0;
        for(int i = 2;i < len;++i)
        {
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                dp = 1 + dp;
                sum += dp;
            }
            else
                dp = 0;
        }
        return sum;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        //return Violent(A);
        // int len = A.size();
        // int count = 0;
        // DFS(A,len - 1,count);
        // return count;
        return DPCore(A);
    }
};
// @lc code=end

