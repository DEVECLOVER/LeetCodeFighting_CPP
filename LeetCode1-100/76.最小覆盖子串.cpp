/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
//总结到滑动窗口的一般套路。
//left right 的初始化，从头开始
// 接着right向右滑动，知道满足要求，得到一个值
//接着left向右移动，直到不满足要求，回到上一步，继续开始
//重要在于细节的处理，下标的移动，越界的判断等等
    string GMT_SlidingWin(string s,string t)
    {
        unordered_map<char,int> objmap;
        unordered_map<char,int> sourcemap;
        int left = 0;
        int right = 0;
        int count = 0;
        int start = 0;
        int minlen = INT_MAX;
        for(auto ch : t)
            ++objmap[ch];
        while(right < s.size())
        {
            auto ch = s[right];
            if(objmap.count(ch))  //objmap[s[right]]
            {
                //++sourcemap[s[right]];
                if(++sourcemap[ch] == objmap[ch])
                    ++count;
            }
            ++right; //把++right放在此处，下面 right - left 正好就是间隔的长度
            //count == t.size()  开始写成这样 害我好找啊！
            while(count == objmap.size())
            {
                if(right - left < minlen)
                {
                    start = left;
                    minlen = right - left;
                }
                ch = s[left];
                if(objmap.count(ch))
                {
                    //--sourcemap[s[left]];
                    if(--sourcemap[ch] < objmap[ch])
                        --count;
                }
                ++left; //这里也要想清楚，为什么 ++left 放在此处，而不是if 的上面
            }
        }
        return minlen == INT_MAX ? "" : s.substr(start,minlen);
    }
    string minWindow(string s, string t) {
        return GMT_SlidingWin(s,t);
    }
};
// @lc code=end

