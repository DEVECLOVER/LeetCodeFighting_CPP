/*
 * @lc app=leetcode.cn id=877 lang=cpp
 *
 * [877] 石子游戏
 */

// @lc code=start
class Solution {
public:
//递归超时  时间复杂度为 指数级
    int Fir(vector<int>& piles,int left,int right)
    {
        if(left == right)
            return piles[left];
        return max(piles[left] + Sec(piles,left + 1,right),piles[right] + Sec(piles,left,right - 1));
    }
    int Sec(vector<int>& piles,int left,int right)
    {
        if(left == right)
            return 0;
        return min(Fir(piles,left + 1,right),Fir(piles,left,right - 1));
    }
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        int fir[len][len] = {0};
        int sec[len][len] = {0};
        for(int j = 0;j < len;++j)
        {
            fir[j][j] = piles[j];
            for(int i = j - 1;i >= 0;--i)
            {
                fir[i][j] = max(piles[i] + sec[i + 1][j],piles[j] + sec[i][j - 1]);
                sec[i][j] = min(fir[i + 1][j],fir[i][j - 1]);
            }
        }
        return fir[0][len - 1] > sec[0][len - 1];

        
        //return Fir(piles,0,piles.size() - 1) > Sec(piles,0,piles.size() - 1);
    }
};
// @lc code=end

