/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
//采用后序遍历，不会重复
    int DiaCore(TreeNode* root,int& maxlen)
    {
        if(root == NULL)
            return 0;
        int leftlen = DiaCore(root->left,maxlen);
        int rightlen = DiaCore(root->right,maxlen);
        maxlen = max(maxlen,1 + leftlen + rightlen);
        return 1 + max(leftlen,rightlen);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int maxlen = 0;
        DiaCore(root,maxlen);
        return maxlen - 1;//为了不减一，可以在max函数中，去掉 1 + 
    }
};
// @lc code=end

