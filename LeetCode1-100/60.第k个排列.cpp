/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

// @lc code=start
class Solution {
public:
//第一次想法，但是交换产生的序列是不正确的，这一点之前没有认识清楚  [NAC]
    void BackCore(int& count,int index,string& scr,bool& flag,string& res,const int& n,const int& k)
    {
        if(index >= n)
        {
            ++count;
            if(count == k)
            {
                res = scr;
                flag = false;
            }
            return;
        }
        for(int i = index;flag && i < n;++i)
        {
            swap(scr[index],scr[i]);
            BackCore(count,index + 1,scr,flag,res,n,k);
            swap(scr[index],scr[i]);
        }
    }
    string KthPer(int n,int k)
    {
        string scr = "";
        string res = "";
        for(int i = 1;i <= n;++i)
            scr += (i + '0');
        if(k < 2)
            return scr;
        bool flag = true;
        int count = 0;
        BackCore(count,0,scr,flag,res,n,k);
        return res;
    }
// [AC]
    string STL(int n,int k)
    {
        string s = string("123456789").substr(0,n);
        for(int j = 1; j < k; ++j) 
            next_permutation(s.begin(), s.end()); //罪过 罪过, 谢罪！
        return s;
    }    
    
    string getPermutation(int n, int k) {
        //return KthPer(n,k);
        return STL(n,k);
    }
};
// @lc code=end

