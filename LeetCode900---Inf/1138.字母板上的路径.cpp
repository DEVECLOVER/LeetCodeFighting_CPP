/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */

// @lc code=start
class Solution {
public:
    string alphabetBoardPath(string target) {
        string res;
        int prex = 0;
        int prey = 0;
        int stepx = 0;
        int stepy = 0;
        for(auto ch : target)
        {
            int curx = (ch - 'a')%5;
            int cury = (ch - 'a') /5;
            stepx = curx - prex;
           stepy = cury - prey;
           if(ch == 'z')
           {
               while(stepx < 0)
               {
                   res += 'L';
                   ++stepx;
               }
               while(stepy > 0)
               {
                   res += 'D';
                   --stepy;
               }
           }
           else
           {
               while(stepy > 0) //顺序还不能错   D U R L
               {
                   res += 'D';
                   --stepy;
               }
               while(stepy < 0)
               {
                   res += 'U';
                   ++stepy;
               }
               while(stepx > 0)
               {
                   res += 'R';
                   --stepx;
               }
               while(stepx < 0)
               {
                   res += 'L';
                   ++stepx;
               }
           }
           res += '!';
           prex = curx;
           prey = cury;
            
        }
        return res;
    }
};
// @lc code=end

