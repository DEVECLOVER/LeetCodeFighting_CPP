/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
public:
//集中注意力  快速分析问题 
//意识到 矛盾只在左右括号 与其他字符无关
// 而对于每个字符，只有两种状态，留或者不留
// 步骤：1.判断字符串是否有效  2.通过回溯得到所有可能结果，判断即可。

// BFS  判断删除一个字符，两个呢？三个呢？……，进而得到结果
    vector<string> removeInvalidParentheses(string s) 
    {

    }
};
// @lc code=end

