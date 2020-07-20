/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    void BSTCore(TreeNode* root,int& addnum)
    {
        if(root == NULL)
            return ;
        BSTCore(root->right,addnum);
        root->val += addnum;
        addnum = root->val;
        BSTCore(root->left,addnum);
    }
    TreeNode* convertBST(TreeNode* root) {
        int addnum = 0;
        BSTCore(root,addnum);
        return root;
    }
};
// @lc code=end

