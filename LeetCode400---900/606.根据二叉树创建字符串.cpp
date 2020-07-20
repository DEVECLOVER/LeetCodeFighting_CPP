/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
// 很好的做法，自己刚开始还想着，空节点加上（），然后最后再消掉呢？这种思维要审视。
    string Cool(TreeNode* t)
    {
        if(t == nullptr)
            return "";
        if(t->left == nullptr && t->right == nullptr)
            return to_string(t->val);
        if(t->right == nullptr)
            return to_string(t->val) + "(" + Cool(t->left) + ")";
        return to_string(t->val) + "(" + Cool(t->left) + ")(" + Cool(t->right) + ")";
    }
    string tree2str(TreeNode* t) {
        return Cool(t);
    }
};
// @lc code=end

