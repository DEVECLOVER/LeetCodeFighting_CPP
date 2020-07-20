/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //第一想法是借鉴前面的匹配子树，后序遍历
    //建立两个vector ,第一个存储所有子树，每添加一个子树，都会与前面的子树匹配，如果存在重复，添加到第二个中
    //第二个，存储重复的子树
    //后来看到，题解将树序列化，匹配就转换为字符串匹配了
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {

    }
};
// @lc code=end

