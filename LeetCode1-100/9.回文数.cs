/*
 * @lc app=leetcode.cn id=9 lang=csharp
 *
 * [9] 回文数
 */

// @lc code=start
public class Solution {
    public bool IsPalindrome(int x) {
            if (x < 0)
            {
                return false;
            }
            if (x == 0)
            {
                return true;
            }
            List<int> numlist = new List<int>();
            while (x != 0)
            {
                numlist.Add(x % 10);
                x = x / 10;
            }
            int len = numlist.Count;
            for (int i = 0; i < len / 2; i++)
            {
                if (numlist[i] != numlist[len - 1 - i])
                {
                    return false;
                }
            }
            return true;

    }
}
// @lc code=end

